/*
 * main.o
 *
 *  Created on: June 21, 2014
 *      Author: Synergiance
 *
 */

// Count with a long long with another thread and display it on screen

//#include <iostream>
//#include <stdio.h>
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
    unsigned char a;
    long long b;
    unsigned char c;
    char d[64];
    unsigned char e;
    signal(SIGINT, sigHandler);
    stop = false;
    counter = std::thread(thrMain);
    while (!stop) {
        //std::cout<<number<<std::endl;
        //printf("%lld\n", number);
        a = 0;
        b = number;
        for (c = 0; c < 63 && b > 0; c++) {
            a = b % 10;
            b /= 10;
            d[c] = a + 48;
        }
        d[c] = '\0';
        for (a = --c; c > a / 2; c--) {
            e = d[c];
            d[c] = d[a-c];
            d[a-c] = e;
        }
        puts(d);
    }
    counter.join();
}
