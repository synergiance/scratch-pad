/*
 * main.cpp
 *
 *  Created on 18 April 2014
 *      By: Synergiance
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
bool ready = false;

ostream& scout(ostream& stream)
{
	mtx.lock();
	cout(stream);
	mtx.unlock();
}

void showID(int ID)
{
    unique_lock<mutex> lck(mtx);
	while (!ready) cv.wait(lck);
	// 3 2 1 GO!
	scout<<"Thread #"<<ID<<endl;
}

void go() {
    unique_lock<mutex> lck(mtx);
    ready = true;
    cv.notify_all();
}

int main ()
{
    std::thread threads[10];
    // spawn 20 threads:
    for (int i=0; i<20; ++i)
        threads[i] = thread(showID,i);

    cout << "10 threads ready to race...\n";
    go();                       // go!

    for (auto& th : threads) th.join();

    return 0;
}

