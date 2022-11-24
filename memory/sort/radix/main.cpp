/*
 *   Filename: main.cpp
 *
 * Created on: 20 October 2016
 *     Author: Synergiance
 *
 * Just a simple function call with statistics (if I can figure that out)
 */

#include "radix.h"
//#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<unsigned> array;
    for (unsigned c = 1; c <= 2000000; c++) array.push_back(c);
    std::random_shuffle(array.begin(), array.end());
    //std::cout<<"Input:\n";
    //for(const unsigned& v: array) std::cout<<v<<" ";
    sort(array);
    //std::cout<<"\nOutput\n";
    //for(const unsigned& v: array) std::cout<<v<<" ";
    //std::cout<<std::endl;
    return 0;
}
