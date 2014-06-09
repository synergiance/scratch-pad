/* 
 * memorymapper.cpp
 *
 * FOR EDUCATIONAL PURPOSES ONLY !!!
 *
 * Synergiance
 * 6/8/2014
 */

#include <stdio.h>
#include <signal.h>

char * address;
char c = 'f';

void sigHandler(int signum)
{
    if (signum == SIGSEGV)
    {
        address++;
        printf("\n%p: ", address);
        printf("%p", *address);
    }
    return;
}

int main()
{
    signal(SIGSEGV, sigHandler);
    while (true) printf("%p",*++address);
    return 0;
}