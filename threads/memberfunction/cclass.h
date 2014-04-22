/*
 * cclass.h
 *
 *  Created on 22 April 2014
 *      By: Tim Gerety
 */

#include <thread>

using namespace std;

#ifndef CCLASS_H_
#define CCLASS_H_

class CClass
{
public:
	void start();
	void wait();
private:
	void main();
	thread thrClass;
};

#endif /* CCLASS_H_ */
