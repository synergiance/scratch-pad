/*
 *   Filename: main.c
 *
 * Created on: 23 January 2016
 *     Author: Synergiance
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
 * that the 6th prime is 13.
 *
 * What is the 10001st prime number?
 */

#include <stdio.h>
#include <stdlib.h>

#define TARGET 10001
#define SVSZ 1024

int main(int argc, char *argv[]) {
    size_t count = 1;
    int flag;
    size_t c;
    unsigned long long offset = 0;
    size_t d;
    size_t e;
    size_t target = TARGET;
    size_t svsz = SVSZ;
    char tgtapnd[3];
    char chr;
    unsigned char hitMax = 0;

    if (argc > 1) {
        target = atoi(argv[1]);
    }

    printf("Prime: %zu\n", target);

    c = target % 10;

    if ((target / 10) % 10 == 1) {
        tgtapnd[0] = 't';
        tgtapnd[1] = 'h';
    } else if (c == 1) {
        tgtapnd[0] = 's';
        tgtapnd[1] = 't';
    } else if (c == 2) {
        tgtapnd[0] = 'n';
        tgtapnd[1] = 'd';
    } else if (c == 3) {
        tgtapnd[0] = 'r';
        tgtapnd[1] = 'd';
    } else {
        tgtapnd[0] = 't';
        tgtapnd[1] = 'h';
    }
    tgtapnd[2] = 0;

    printf("Creating array\n");

    unsigned long long * primes;
    char * sieve;

    primes = malloc(target * sizeof(long long));

    if (primes == NULL) {
        printf("Memory initialization failed, exiting\n");
        return 1;
    }

    unsigned long long sqcache;

    primes[0] = 2; //seed

    printf("Ready to calc!\n");

    while (count < target) {
        sieve = calloc(svsz, sizeof(char));
        printf("Sieve: %p\n", sieve);
        if (sieve == NULL) {
            printf("Memory exceeded, backing off!\n");
            svsz /= 2;
            sieve = calloc(svsz, sizeof(char));
            hitMax = 1;
        }
        fflush(stdout);
        //for (c = 0; c < svsz; c++) sieve[c] = 1;
        c = 0;
        e = 0;
        flag = 0;
        while (!flag) {
            while (c < count) {
                sieve[0] = 1;
                if (offset == 0) {
                    sieve[1] = 1;
                }
                for (d = primes[c] - (offset % primes[c]); d < svsz; d += primes[c]) {
                    sieve[d] = 1;
                }
                c++;
            }
            sqcache = primes[count-1] * primes[count-1];
            for (d = e; offset + d < sqcache && d < svsz; d++) {
                if (!sieve[d]) {
                    primes[count++] = d + offset;
                    if (count == target) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (d == svsz) flag = 1;
            e = d;
        }
        offset += svsz;
        if (!hitMax)
            svsz *= 2;
        free(sieve);
    }
    printf("The %zu%s prime is: \x1b[31m%llu\x1b[0m\n", target, tgtapnd, primes[target - 1]);
    return 0;
}
