#include <string>
#include <iostream>

using namespace std;

int main() {
    while (true) {
        string str;
        cout<<": ";
        getline(cin, str);
        if (str == "") break;
        int a = str.find("!");
        int b = str.find("@");
        if (a == -1 || b == -1) {
            cout<<"Invalid\n";
        }
        else {
            cout<<"Nick: "<<str.substr(0,a++)<<endl;
            cout<<"User: "<<str.substr(a,b-a)<<endl;
            cout<<"Host: "<<str.substr(b+1)<<endl;
        }
    }
}