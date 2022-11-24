/*
 *   Filename: time.c
 *
 * Created on: 13 April 2016
 *     Author: Synergiance
 *
 * Converts integers to time
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printhelp(char* str) {
    printf("\n  Usage: %s [time]\n\n", str);
}

int main (int argc, char* argv[]) {
    if (argc == 1) {
        printf("This will print out an integer\n");
    } else if (argc == 2) {
        time_t time;
        if ((time = atoi(argv[1]))) {
            printf("%s", ctime(&time));
        } else {
            printhelp(argv[0]);
        }
    } else {
        printhelp(argv[0]);
    }
}
