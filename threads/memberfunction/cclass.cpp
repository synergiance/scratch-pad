/*
 * cclass.cpp
 *
 *  Created on 22 April 2014
 *      By: Tim Gerety
 */

// Global includes
#include <iostream>
#include <thread>

// Local includes
#include "cclass.h"

using namespace std;

CClass::CClass()
{
    thrClass(CClass::main);
    thrClass.join();
}

void CClass::main()
{
    cout<<"Printing from member function\n";
}
