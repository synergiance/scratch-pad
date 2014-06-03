/*
 * main.cpp
 *
 * Author: Synergiance
 */

#include <iostream>

class Cderp
{
public:
    Cderp* anus;
    int intStorage;
    
    Cderp(int num)
    {
        intStorage = num;
        anus = 0;
    }
    
    void add(int num)
    {
        if (anus == 0)
        {
            char* mem = new char[sizeof(Cderp)];
            anus = new (mem) Cderp(num);
        }
        else
        {
            anus->add(num);
        }
    }
    
    int rem()
    {
        int retVal = 1;
        if (anus == 0)
        {
            retVal = 0;
        }
        else
        {
            if (anus->rem() == 0)
            {
                delete anus;
                anus = 0;
            }
        }
        return retVal;
    }
    
    int get(int num)
    {
        int retVal = intStorage;
        if ((num > 1) && (anus > 0)) retVal = anus->get(num - 1);
        return retVal;
    }
    
    int len()
    {
        int retVal = 1;
        if (anus > 0) retVal += anus->len();
        return retVal;
    }
};

int main()
{
    Cderp TheList(1);
    TheList.add(3);
    TheList.add(16);
    TheList.add(1923);
    TheList.add(8732);
    TheList.add(23);
    TheList.add(7);
    TheList.add(932);
    TheList.add(43);
    TheList.add(76);
    
    int numberOf = TheList.len();
    for (int c = 1; c <= numberOf; c++)
        std::cout<<TheList.get(c)<<std::endl;
    
    std::cout<<std::endl;
    
    TheList.rem();
    numberOf = TheList.len();
    for (int c = 1; c <= numberOf; c++)
        std::cout<<TheList.get(c)<<std::endl;
    
    std::cout<<std::endl<<TheList.get(numberOf + 1)<<std::endl;
}