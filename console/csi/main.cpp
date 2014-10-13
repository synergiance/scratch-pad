/*
 * Created on October 12 2014 by Tim Gerety
 */

#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[]) {
    cout<<"\33[31mTesting\33[0m\n\n";
    for (int c = 0; c < 11; c++) {
        cout<<"\33[A\33[J[";
        for (int d = 0; d < 10; d++) if (d < c) cout<<"="; else cout<<" ";
        cout<<"]\n";
        sleep(1);
    }
    return 0;
}

