/*
 *   Filename: config.h
 * 
 * Created on: 12 January 2016
 *     Author: Synergiance
 *
 * This is a prototype config module that can load recursive configs, of which
 * I have never attempted before, so it's going into the scratch-pad.
 */

#include <string> // C++ strings include
#include <vector> // C++ vector arrays

using std::string;
using std::vector;

#ifndef CONFIG_H_
#define CONFIG_H_

class CConfig
{
public:
    CConfig(string config);            // We will only initialize with either
    CConfig(string type, string data); // a config string or a type and name

    CConfig &operator[] (size_t n);    // Recursivity in array syntax
    vector<CConfig> values;

    string format();                   // Returns a formatted string with
                                       // the data in xml format
    string type();
    string getData();
    void setData(string data);

    string getErrors();
private:
    string valueType;
    string valueData;
    string errBuf;
    void addError(string error);
    bool parseHeader(string header, string& type, string& data);
    void trimWhite(string& str);
    bool parseGuts(string str);
};

#endif /* CONFIG_H_ */
