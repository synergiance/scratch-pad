/*
 * main.o
 *
 *  Created on: June 21, 2014
 *      Author: Synergiance
 *
 */

// Count with a long long with another thread and display it on screen

#include <iostream>
#include <signal.h>
#include <thread>

using namespace std;

bool stop;
long long number;
thread counter;

void sigHandler(int signum)
{
    stop = true;
}

void thrMain()
{
    while (!stop) {
        number++;
    }
}

int main()
{
    signal(SIGINT, sigHandler);
    stop = false;
    counter = thread(thrMain);
    while (!stop) {
        cout<<number<<endl;
    }
    counter.join();
}
