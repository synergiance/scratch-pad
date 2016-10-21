/*
 *   Filename: radix.cpp
 *
 * Created on: October 20 2016
 *     Author: Synergiance
 *
 * Radix sort is an algorithm that contains no comparisons, instead it sorts
 * based on a digit of the number, and works its way up.  By preserving input
 * order, a list will end up being completely sorted by the time the final
 * pass through is complete.
 *
 */

#include <vector>
#include "radix.h"

void sort(std::vector<unsigned> & a) {
    unsigned h = 0;
    for (std::size_t c = 0; c < a.size(); c++) if (a[c] > h) h = a[c];
    if (h == 0) return;
    std::size_t i = 0;
    while (h > 1) {
        h >>= 1;
        i++;
    }
    unsigned d = 1;
    for(std::size_t c = 0; c <= i; c++) {
        std::vector<unsigned> arraylow;
        std::vector<unsigned> arrayhigh;
        for (const unsigned& v: a) {
            if (v & d) arrayhigh.push_back(v);
            else arraylow.push_back(v);
        }
        a.clear();
        for (const unsigned& v: arraylow) a.push_back(v);
        for (const unsigned& v: arrayhigh) a.push_back(v);
        d <<= 1;
    }
}
