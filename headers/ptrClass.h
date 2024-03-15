#pragma once
#include <iostream>

template <typename T>
struct ptrStruct
{
public:
    T *getPtr()
    {
        if (IsDeleted)
        {
            throw std::runtime_error("Cannot get value of deleted pointer");
            return nullptr;
        }
        else if (ptr == nullptr)
        {
            throw std::runtime_error("Cannot get value of null pointer");
            return nullptr;
        }
        else 
        {
            return ptr;
        }
    }
    void setPtr(T *newPtr)
    {
        ptr = newPtr;
    }
    int getCount()
    {
        return count;
    }
    void increaseCount()
    {
        ++count;
    }
    void decreaseCount()
    {
        --count;
    }
    void del(ptrStruct<T> parentPtr)
    {
        if (!IsDeleted && ptr != nullptr)
        {
            if (IsCopy && parentPtr.ptr != nullptr)
            {    
                if (parentPtr.count > 1)
                {                  
                    IsDeleted = true;
                    std::cout << "1";
                    parentPtr.decreaseCount();
                }
                else if (parentPtr.count == 1)
                {
                    IsDeleted = true;
                    std::cout << "2";
                    delete ptr;
                    parentPtr.decreaseCount();
                }
            }
            else if (!IsCopy)
            {
                if (count > 1)
                {
                    std::cout << "3";
                    IsDeleted = true;
                    decreaseCount();
                }
                else if (count == 1)
                {
                    IsDeleted = true;
                    std::cout << "4";
                    decreaseCount();
                    delete ptr;
                }
            }
        }
    }
    void setCopyVar(bool val)
    {
        IsCopy = val;
    }
    void setDeletedVar(bool val)
    {
        IsDeleted = val;
    }
    void setCountVar(int val)
    {
        count = val;
    }
protected:
    bool IsCopy = false;
    bool IsDeleted = false;
    int count = 0;
    T *ptr = new T;
};

template <typename T>
class ptrClass
{
public:
    ptrClass();
    ptrClass(T *ptr)
    {
        ptrInfo.setPtr(ptr);
    }
    ptrClass(const ptrClass<T> &other) : ptrInfo((other.ptrInfo))
    {
        parentPtr = other.ptrInfo;
        ptrInfo.setCopyVar(true);
        ptrInfo.setDeletedVar(false);
        parentPtr.increaseCount();
        std::cout << parentPtr.getCount() << std::endl;
        std::cout << ptrInfo.getCount() << std::endl;
    }
    ~ptrClass()
    {
        ptrInfo.del(ptrInfo);
    }
    T &operator*() 
    {
        return *(ptrInfo.getPtr());
    }
    void deletePtr()
    {
        std::cout << ptrInfo.getCount() << std::endl;
        ptrInfo.del(ptrInfo);
    }
    int getCount()
    {
        return ptrInfo.getCount();
    }

private:
    ptrStruct<T> ptrInfo;
    ptrStruct<T> parentPtr;
};