/*
 * main.o
 *
 *  Created on: June 21, 2014
 *      Author: Synergiance
 *
 */

// Count with a long long with another thread and display it on screen

//#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <thread>

//using namespace std;

bool stop;
long long number;
std::thread counter;

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
    counter = std::thread(thrMain);
    while (!stop) {
        //std::cout<<number<<std::endl;
        //puts(number);
        printf("%lld\n", number);
    }
    counter.join();
}
