/*
 * Filename: calendar.c
 *  Created: 23 December, 2017
 *   Author: Synergiance
 *
 * Source: https://xkcd.com/1930/
 *
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

char* sp1 = "Did you know that ";
char* sp2o1p1 = "the ";
char* sp2o1p2o1 = "fall ";
char* sp2o1p2o2 = "spring ";
char* sp2o1p3 = "equinox ";
char* sp2o2p1 = "the ";
char* sp2o2p2o1 = "winter ";
char* sp2o2p2o2 = "summer ";
char* sp2o2p3o1 = "solstice ";
char* sp2o2p3o2 = "olympics ";
char* sp2o3p1 = "the ";
char* sp2o3p2o1 = "earliest ";
char* sp2o3p2o2 = "latest ";
char* sp2o3p3o1 = "sunrise ";
char* sp2o3p3o2 = "sunset ";
char* sp2o4p1 = "daylight ";
char* sp2o4p2o1 = "saving ";
char* sp2o4p2o2 = "savings ";
char* sp2o4p3 = "time ";
char* sp2o5p1 = "leap ";
char* sp2o5p2o1 = "day ";
char* sp2o5p2o2 = "year ";
char* sp2o6 = "easter ";
char* sp2o7p1 = "the ";
char* sp2o7p2o1 = "harvest ";
char* sp2o7p2o2 = "super ";
char* sp2o7p2o3 = "blood ";
char* sp2o7p3 = "moon ";
char* sp2o8 = "shark week ";
char* sp2o9 = "toyota truck month ";
char* sp3o1p1 = "happens ";
char* sp3o1p2o1 = "earlier ";
char* sp3o1p2o2 = "later ";
char* sp3o1p2o3 = "at the wrong time ";
char* sp3o1p3 = "every year ";
char* sp3o2p1 = "drifts out of sync with the ";
char* sp3o2p2o1 = "sun ";
char* sp3o2p2o2 = "moon ";
char* sp3o2p2o3 = "zodiac ";
char* sp3o2p2o4p1o1 = "gregorian ";
char* sp3o2p2o4p1o2 = "mayan ";
char* sp3o2p2o4p1o3 = "lunar ";
char* sp3o2p2o4p1o4 = "iPhone ";
char* sp3o2p2o4p2 = "calendar ";
char* sp3o2p2o5 = "atomic clock in Colorado ";
char* sp3o3p1 = "might ";
char* sp3o3p2o1 = "not happen ";
char* sp3o3p2o2 = "happen twice ";
char* sp3o3p3 = "this year ";
char* sp4 = "because of ";
char* sp5o1p1 = "time zone legislation in ";
char* sp5o1p2o1 = "Indiana";
char* sp5o1p2o2 = "Arizona";
char* sp5o1p2o3 = "Russia";
char* sp5o2 = "a decree by the pope in the 1500s";
char* sp5o3p1o1 = "precession ";
char* sp5o3p1o2 = "liberation ";
char* sp5o3p1o3 = "nutation ";
char* sp5o3p1o4 = "libation ";
char* sp5o3p1o5 = "eccentricity ";
char* sp5o3p1o6 = "obliquity ";
char* sp5o3p2 = "of the ";
char* sp5o3p3o1 = "moon";
char* sp5o3p3o2 = "sun";
char* sp5o3p3o3 = "earth's axis";
char* sp5o3p3o4 = "equator";
char* sp5o3p3o5 = "prime meridian";
char* sp5o3p3o6p1o1 = "international date ";
char* sp5o3p3o6p1o2 = "mason-dixon ";
char* sp5o3p3o6p2 = "line";
char* sp5o4 = "magnetic field reversal";
char* sp5o5p1 = "an arbitrary decision by ";
char* sp5o5p2o1 = "Benjamin Franklin";
char* sp5o5p2o2 = "Isaac Newton";
char* sp5o5p2o3 = "FDR";
char* sp6 = "? Apparently ";
char* sp7o1 = "it causes a predictable increase in car accidents.";
char* sp7o2 = "that's why we have leap seconds.";
char* sp7o3 = "scientists are really worried.";
char* sp7o4p1 = "it was even more extreme during the ";
char* sp7o4p2o1 = "bronze age.";
char* sp7o4p2o2 = "ice age.";
char* sp7o4p2o3 = "cretaceous.";
char* sp7o4p2o4 = "1990s.";
char* sp7o5p1 = "there's a proposal to fix it, but it ";
char* sp7o5p2o1 = "will never happen.";
char* sp7o5p2o2 = "actually makes things worse.";
char* sp7o5p2o3 = "is stalled in congress.";
char* sp7o5p2o4 = "might be unconstitutional.";
char* sp7o6= "it's getting worse and no one knows why.";

void subject() {
    int a;
    switch(rand() % 9) {
        case 0:
            printf("%s", sp2o1p1);
            printf("%s", rand() % 2 ? sp2o1p2o1 : sp2o1p2o2);
            printf("%s", sp2o1p3);
            break;
        case 1:
            printf("%s", sp2o2p1);
            printf("%s", rand() % 2 ? sp2o2p2o1 : sp2o2p2o2);
            printf("%s", rand() % 2 ? sp2o2p3o1 : sp2o2p3o2);
            break;
        case 2:
            printf("%s", sp2o3p1);
            printf("%s", rand() % 2 ? sp2o3p2o1 : sp2o3p2o2);
            printf("%s", rand() % 2 ? sp2o3p3o1 : sp2o3p3o2);
            break;
        case 3:
            printf("%s", sp2o4p1);
            printf("%s", rand() % 2 ? sp2o4p2o1 : sp2o4p2o2);
            printf("%s", sp2o4p3);
            break;
        case 4:
            printf("%s", sp2o5p1);
            printf("%s", rand() % 2 ? sp2o5p2o1 : sp2o5p2o2);
            break;
        case 5:
            printf("%s", sp2o6);
            break;
        case 6:
            printf("%s", sp2o7p1);
            a = rand() % 3;
            if (a == 0) printf("%s", sp2o7p2o1);
            else if (a == 1) printf("%s", sp2o7p2o2);
            else printf("%s", sp2o7p2o3);
            printf("%s", sp2o7p3);
            break;
        case 7:
            printf("%s", sp2o8);
            break;
        case 8:
            printf("%s", sp2o9);
            break;
    }
}

void predicate() {
    int a, b;
    a = rand() % 3;
    if (a == 0) {
        printf("%s", sp3o1p1);
        b = rand() % 3;
        if (b == 0) printf("%s", sp3o1p2o1);
        else if (b == 1) printf("%s", sp3o1p2o2);
        else printf("%s", sp3o1p2o3);
        printf("%s", sp3o1p3);
    } else if (a == 1) {
        printf("%s", sp3o2p1);
        switch(rand() % 5) {
            case 0:
                printf("%s", sp3o2p2o1);
                break;
            case 1:
                printf("%s", sp3o2p2o2);
                break;
            case 2:
                printf("%s", sp3o2p2o3);
                break;
            case 3:
                b = rand() % 4;
                if (b == 0) printf("%s", sp3o2p2o4p1o1);
                else if (b == 1) printf("%s", sp3o2p2o4p1o2);
                else if (b == 2) printf("%s", sp3o2p2o4p1o3);
                else printf("%s", sp3o2p2o4p1o4);
                printf("%s", sp3o2p2o4p2);
                break;
            case 4:
                printf("%s", sp3o2p2o5);
                break;
        }
    } else {
        printf("%s", sp3o3p1);
        printf("%s", rand() % 2 ? sp3o3p2o1 : sp3o3p2o2);
        printf("%s", sp3o3p3);
    }
}

void because() {
    switch(rand() % 5) {
        case 0:
            printf("%s", sp5o1p1);
            switch(rand() % 3) {
                case 0:
                    printf("%s", sp5o1p2o1);
                    break;
                case 1:
                    printf("%s", sp5o1p2o2);
                    break;
                case 2:
                    printf("%s", sp5o1p2o3);
                    break;
            }
            break;
        case 1:
            printf("%s", sp5o2);
            break;
        case 2:
            switch(rand() % 6) {
                case 0:
                    printf("%s", sp5o3p1o1);
                    break;
                case 1:
                    printf("%s", sp5o3p1o2);
                    break;
                case 2:
                    printf("%s", sp5o3p1o3);
                    break;
                case 3:
                    printf("%s", sp5o3p1o4);
                    break;
                case 4:
                    printf("%s", sp5o3p1o5);
                    break;
                case 5:
                    printf("%s", sp5o3p1o6);
                    break;
            }
            printf("%s", sp5o3p2);
            switch(rand() % 6) {
                case 0:
                    printf("%s", sp5o3p3o1);
                    break;
                case 1:
                    printf("%s", sp5o3p3o2);
                    break;
                case 2:
                    printf("%s", sp5o3p3o3);
                    break;
                case 3:
                    printf("%s", sp5o3p3o4);
                    break;
                case 4:
                    printf("%s", sp5o3p3o5);
                    break;
                case 5:
                    printf("%s", rand() % 2 ? sp5o3p3o6p1o1 : sp5o3p3o6p1o2);
                    printf("%s", sp5o3p3o6p2);
                    break;
            }
            break;
        case 3:
            printf("%s", sp5o4);
            break;
        case 4:
            printf("%s", sp5o5p1);
            switch(rand() % 3) {
                case 0:
                    printf("%s", sp5o5p2o1);
                    break;
                case 1:
                    printf("%s", sp5o5p2o2);
                    break;
                case 2:
                    printf("%s", sp5o5p2o3);
                    break;
            }
            break;
    }
}

void apparently() {
    switch(rand() % 6) {
        case 0:
            printf("%s", sp7o1);
            break;
        case 1:
            printf("%s", sp7o2);
            break;
        case 2:
            printf("%s", sp7o3);
            break;
        case 3:
            printf("%s", sp7o4p1);
            switch(rand() % 4) {
                case 0:
                    printf("%s", sp7o4p2o1);
                    break;
                case 1:
                    printf("%s", sp7o4p2o2);
                    break;
                case 2:
                    printf("%s", sp7o4p2o3);
                    break;
                case 3:
                    printf("%s", sp7o4p2o4);
                    break;
            }
            break;
        case 4:
            printf("%s", sp7o5p1);
            switch(rand() % 4) {
                case 0:
                    printf("%s", sp7o5p2o1);
                    break;
                case 1:
                    printf("%s", sp7o5p2o2);
                    break;
                case 2:
                    printf("%s", sp7o5p2o3);
                    break;
                case 3:
                    printf("%s", sp7o5p2o4);
                    break;
            }
            break;
        case 5:
            printf("%s", sp7o6);
            break;
    }
}

int main() {
    srand(time(NULL));
    printf("%s", sp1);
    subject();
    predicate();
    printf("%s", sp4);
    because();
    printf("%s", sp6);
    apparently();
    printf("\n");
    return 0;
}
