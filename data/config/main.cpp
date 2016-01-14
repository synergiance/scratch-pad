/*
 *   Filename: main.cpp
 *
 * Created on: 13 January 2016
 *     Author: Synergiance
 *
 * Tests our config module
 */

#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>

#define OUTFILE = "config.out"
#define  INFILE = "config.in"

int main()
{// This is where we begin
    CConfig test("testtype", "test value");
    for (size_t c = 0; c < 16; c++) {
        char * buf = nullptr;
        sprintf(buf, "%zu", c);
        CConfig addedThing("addedtype", string(buf));
        test.values.push_back(addedThing);
    }
    CConfig recursiveHolder("Recursive holder", "");
    for (size_t c = 0; c < 4; c++) {
        CConfig otherThing("key", "");
        recursiveHolder.values.push_back(otherThing);
    }
    test.values.push_back(recursiveHolder);
    std::string str = test.format();
    const char * buf;
    for (;;) {
        if (str.size() == 0)
            break;
        buf = str.substr(0, 64).c_str();
        ssize_t c = str.size();
        if (c > 64) c = 64;
        write(STDOUT_FILENO, buf, c);
        str.erase(0, 64);
    }
    write(STDOUT_FILENO, "\n", 1);
    return 0;
}
