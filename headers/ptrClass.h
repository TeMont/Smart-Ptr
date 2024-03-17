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
            std::cout << "Cannot get value of deleted pointer" << std::endl;
            return nullptr;
        }
        else if (ptr == nullptr)
        {
            std::cout << "Cannot get value of null pointer" << std::endl;
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
    void del(ptrStruct<T> &parentPtr)
    {
        if (!IsDeleted && ptr != nullptr)
        {
            if (IsCopy && parentPtr.ptr != nullptr)
            {    
                if (parentPtr.count > 0)
                {                  
                    IsDeleted = true;
                    parentPtr.decreaseCount();
                }
                else if (parentPtr.count == 0)
                {
                    IsDeleted = true;
                    delete ptr;
                    parentPtr.decreaseCount();
                }
            }
            else if (!IsCopy)
            {
                    std::cout << count;
                if (count > 1)
                {
                    IsDeleted = true;
                    decreaseCount();
                }
                else if (count == 1)
                {
                    IsDeleted = true;
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
    bool getCopyVar()
    {
        return IsCopy;
    }
    bool getDeletedVar()
    {
        return IsDeleted;
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
    }
    ~ptrClass()
    {
        // ptrInfo.del(parentPtr);
    }
    T &operator*() 
    {
        return *(ptrInfo.getPtr());
    }
    void deletePtr()
    {
        ptrInfo.del(parentPtr);
    }
    int getCount()
    {
        return ptrInfo.getCount();
    }
    void swap(ptrClass<T> &ptrToSwap)
    {
        ptrClass<T> temp = ptrToSwap;

        ptrToSwap.ptrInfo = ptrInfo;
        ptrToSwap.parentPtr = parentPtr;

        ptrInfo = temp.ptrInfo;
        parentPtr = temp.parentPtr;


        temp.deletePtr();
    }
    bool isUnique()
    {
        if (!ptrInfo.getCopyVar() || parentPtr.getCount() == 0)
        {
            return true;
        }
        else 
        {
            std::cout << "C: " << parentPtr.getCount() << '\t';
            return false;
        }
    }

private:
    ptrStruct<T> ptrInfo;
    ptrStruct<T> parentPtr;
};