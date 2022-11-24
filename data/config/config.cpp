/*
 *   Filename: config.cpp
 * 
 * Created on: 12 January 2016
 *     Author: Synergiance
 *
 * This is a prototype config module that can load recursive configs, of which
 * I have never attempted before, so it's going into the scratch-pad.
 */

#include <string> // C++ strings
#include <vector> // C++ vector arrays

#include "config.h"

using std::string;
using std::vector;

CConfig::CConfig(string config)
{// Pass a configuration string here to get a config
    bool allGood = true;
    string str = config;
    string t, d;
    trimWhite(str);
    if (str.empty())
        allGood = false;
    if (allGood) {
        if ((str.front() == '<') && (str.back() == '>')) {
            if (str.at(str.size() - 2) == '/') {
                if ((str.size() > 4) && (str.at(str.size() - 3) == ' ')) {
                    allGood = parseHeader(str.substr(1, str.size() - 4), t, d);
                } else {
                    allGood = false;
                    addError("Parsing error: expected content");
                }
            } else {
                size_t a = str.find(">");
                size_t b = str.rfind("<");
                if ((a == str.length() - 1) || (b == 0)) {
                    allGood = false;
                    addError("Parsing error: malformed tag");
                }
                if (allGood)
                    allGood = parseHeader(str.substr(1, a - 1), t, d);
                if (allGood) {
                    if (str.compare(b + 1, str.size() - b - 2, "/" + t) != 0) {
                        allGood = false;
                        addError("Mismatched tag: " + t);
                    } else {
                        allGood = parseGuts(str.substr(a + 1, b - a - 1));
                    }
                }
            }
        } else {
            allGood = false;
            addError("Parsing error: expecting <>");
        }
    }
    if (allGood) {
        valueType = t;
        valueData = d;
    }
}

bool CConfig::parseGuts(string str)
{// Parse the guts of the xml looking for tags
    size_t cursor    = 0;
    size_t front;
    size_t back;
    size_t numLayers = 0;
      bool allGood   = true;
    string buf       = str;
    vector<CConfig> array;
    vector<string>  layers;

    for (;;) {
        front = buf.find('<', cursor);
        back  = buf.find('>', cursor);
        if ((front == string::npos) && (back == string::npos)) {
            break;
        } else if ((front == string::npos) || (back == string::npos)) {
            allGood = false;
            addError("Parsing error: <> mismatch");
            break;
        } else {
            if (buf.at(back - 1) == '/') {
                if (numLayers == 0) {
                    CConfig val(buf.substr(0, back + 1));
                    if (val.type().empty()) {
                        allGood = false;
                        addError(val.getErrors());
                        break;
                    }
                    array.push_back(val);
                    buf = buf.substr(back + 1);
                    cursor = 0;
                } else {
                    cursor = back + 1;
                }
            } else {
                if (buf.at(front + 1) == '/') {
                    if (buf.compare(front+2,back-front-2,layers.back())==0) {
                        numLayers -= 1;
                        layers.pop_back();
                        if (numLayers == 0) {
                            CConfig val(buf.substr(0, back + 1));
                            if (val.type().empty()) {
                                allGood = false;
                                addError(val.getErrors());
                                break;
                            }
                            array.push_back(val);
                            buf = buf.substr(back + 1);
                            cursor = 0;
                        }
                    } else {
                        allGood = false;
                        addError(string("Type mismatch: ") + layers.back());
                    }
                } else {
                    size_t b = buf.find('=');
                    if (b < back) {
                        layers.push_back(buf.substr(front+1,b-front-1));
                    } else {
                        layers.push_back(buf.substr(front+1,back-front-1));
                    }
                    numLayers += 1;
                    cursor = back + 1;
                }
            }
        }
    }
    if (allGood) {
        values = array;
    }
    return allGood;
}

void CConfig::trimWhite(string& str)
{// trims white space
    for (;;) {
        if (str.empty()) break;
        if (isspace(str.front()))
            str.erase(0);
        else if (isspace(str.back()))
            str.pop_back();
        else
            break;
    }
}

bool CConfig::parseHeader(string header, string& type, string& data)
{// Parse the header with a bit more room. < > and /> removed
    string t, d;
    bool allGood = true;
    size_t c = 0;
    c = header.find('=');
    if (c == string::npos) {
        t = header;
    } else {
        if ((c > 0) && (header.size() - c > 1)) {
            t = header.substr(0,c);
            d = header.substr(c+1);
            if ((d.front() == '"') && (d.back() == '"')) {
                d = d.substr(1, d.size() - 2);
                for (char a : d) {
                    if (!isprint(a)) {
                        allGood = false;
                        addError("Invalid character: nonprint character");
                    }else if ((a == '<') || (a == '>') || (a == '"')) {
                        allGood = false;
                        addError(string("Invalid character: ") + a);
                    }
                }
            } else {
                allGood = false;
                addError("Parsing error: missing one or more '\"' marks");
            }
        } else {
            allGood = false;
            addError("Parsing error: expected type/data");
        }
    }
    for (char a : t) {
        if (!isalnum(a)) {
            if (isprint(a))
                addError(string("Invalid character: ") + a);
            else
                addError("Invalid character: nonprint character");
            allGood = false;
        }
    }
    if (allGood) {
        type = t;
        data = d;
    }
    return allGood;
}

CConfig::CConfig(string type, string data)
{// Pass a type and a name here to create a config
    bool allGood = true;
    if (type.empty()) {
        addError("Blank type");
        allGood = false;
    }
    for (char e : type)
        if (!isalnum(e))
            allGood = false;
    if (data.size() > 0) {
        for (char e : data) {
            if (!isprint(e))
                allGood = false;
            if ((e == '<') || (e == '>') || (e == '"'))
                allGood = false;
        }
    }
    if (!allGood)
        addError("Invalid characters");
    if (type.empty()) {
        addError("Blank type");
        allGood = false;
    }
    if (allGood) {
        valueType = type;
        valueData = data;
    }
}

string CConfig::format()
{// Formats the data into custom xml format
    string str;
    if (valueType.empty()) return string();
    str = "<" + valueType;
    if (valueData.size() > 0)
        str += "=\"" + valueData + "\"";
    if (values.size() > 0) {
        string str2;
        size_t c;
        str += ">";
        for (CConfig value : values) {
            str += "\n    ";
            str2 = value.format();
            c = 0;
            for (;;) {
                c = str2.find('\n', c);
                if (c == string::npos) break;
                str2.insert(++c, "    ");
            }
            str += str2;
        }
        str += "\n</" + valueType + ">";
    } else {
        str += " />";
    }
    return str;
}

string CConfig::getErrors()
{// Returns error(s) and clears the buffer
    string str = errBuf;
    errBuf = string();
    return str;
}

void CConfig::addError(string error)
{// Adds an error to the error string
    errBuf += error;
    if (errBuf.back() != '\n')
        errBuf += '\n';
}

CConfig &CConfig::operator[] (size_t n)
{ return values[n]; }
string CConfig::type()
{ return valueType; }
string CConfig::getData()
{ return valueData; }

void CConfig::setData(string data)
{// Scan for invalid characters before adding
    bool allGood = true;
    for (char e : data) {
        if (!isprint(e))
            allGood = false;
        else if ((e == '<') || (e == '>') || (e == '"'))
            allGood = false;
    }
    if (!allGood)
        addError("Invalid characters");
    if (data.empty()) {
        allGood = false;
        addError("Empty data");
    }
    valueData = data;
}
