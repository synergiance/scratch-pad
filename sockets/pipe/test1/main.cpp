/*
 * main.cpp
 *
 *  Created on 23 April 2014
 *      By: Tim Gerety
 */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <string>

using namespace std;

int main()
{
    int pfds[2];
    string buf;

    pipe(pfds);

    if (!fork) { // Child
        cout<<"CHILD: Enter some text: ";
        cin>>buf;
        pfds[1]<<buf;
        exit(0);
    } else { // Parent
        pfds>>buf;
        cout<<"PARENT: You typed: "<<buf<<endl;
        wait(NULL);
    }
}
