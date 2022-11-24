/*
 * main.cpp
 *
 *  Created on 17 April 2014
 *      By: Synergiance
 */

// http://www.cplusplus.com/reference/mutex/mutex/lock/

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <thread>
#include <mutex>

using namespace std;

// Global
vector<string> buffer;
mutex mtx;

int accessBuffer(bool adding, string str)
{// Our mutex'd up function for all the fun in the world
    int strCount;
    mtx.lock();
    strCount = buffer.size();
    if (adding)
    {
        cout<<"Adding to buffer: "<<str<<endl;
        buffer.push_back(str);
    }
    else
    {
        cout<<"Removing:\n";
        for (int c = 0; c < strCount; c++)
            cout<<buffer[c]<<endl;
        buffer.clear();
        cout<<"Buffer cleared\n";
    }
    mtx.unlock();
    return strCount;
}

void add(string str)
{// This function adds a string to the buffer
    accessBuffer(true, str);
}

void rem()
{
    int strRem = 0;
    while (strRem < 10)
        strRem += accessBuffer(false, "");
}

int main()
{
    thread threads[10];
    cout<<"Starting threads...\n";
    threads[0] = std::thread(add,"one");
    threads[1] = std::thread(add,"two");
    threads[2] = std::thread(add,"three");
    threads[3] = std::thread(add,"four");
    threads[4] = std::thread(add,"five");
    threads[5] = std::thread(add,"six");
    threads[6] = std::thread(add,"seven");
    threads[7] = std::thread(add,"eight");
    threads[8] = std::thread(add,"nine");
    threads[9] = std::thread(add,"ten");

    thread remover = std::thread(rem);

    for (int c = 0; c < 10; c++) threads[c].join();
    remover.join();

    return 0;
}

