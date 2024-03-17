#include <memory>
#include <iostream>
#include "../headers/ptrClass.h"

int main()
{
    
    int *x = new int(15);
    int *y = new int(34);

    ptrClass<int> ptr1 = x;
    ptrClass<int> ptr2 = ptr1;


    ptr1.deletePtr();
    
    



    std::shared_ptr<int> pttr1(new int(15));

    return 0;
}