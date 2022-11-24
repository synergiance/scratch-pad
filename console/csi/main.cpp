/*
 * Created on October 12 2014 by Synergiance
 */

#include <iostream>
#include <unistd.h>
#include <limits>

#include "consmanip.h"

using namespace std;

int main(int argc, char* argv[]) {
    initialize();
    cout<<"\33[31mTesting\33[0m\n\n";
    linebuffered(false);
    for (int c = 0; c < 11; c++) {
        cout<<"\33[A\33[J[";
        for (int d = 0; d < 10; d++) if (d < c) cout<<"="; else cout<<" ";
        cout<<"] "<<c*10<<"%\n";
        echo(false);
        sleep(1);
        echo();
    }
    //cin.clear(cin.eofbit);
    //cin.ignore(numeric_limits<streamsize>::max());
    char * buf = new char [100];
    while (cin.good()) {
        cout<<"test1\n";
        //cin.readsome(buf, 100);
        cin.get();
    }
    cout<<"test2\n";
    delete[] buf;
    linebuffered();
    finalize();
    return 0;
}

