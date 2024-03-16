#include <iostream>
#include "../headers/ptrClass.h"

int main()
{
    
    int *x = new int(15);

    ptrClass<int> ptr1 = x;
    ptrClass<int> ptr2 = ptr1;

    std::cout << *ptr1 << std::endl;
    std::cout << *ptr2 << std::endl;

    ptr2.deletePtr();

    std::cout << *ptr1 << std::endl;
    std::cout << *ptr2 << std::endl;

    

    return 0;
}