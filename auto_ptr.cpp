#include <iostream>  
template<typename T>

class AutoPtr
{
    T* data;

public:
    AutoPtr(T* pointer)
    {
        data = pointer;
    }
    AutoPtr(AutoPtr& dataRhs) :
        data(dataRhs.change())
    {
        dataRhs.data = NULL;
    }
    AutoPtr& operator=(const AutoPtr& dataRhs)
    {
        data = dataRhs.change();

        return (*this);
    }
    T& operator*()
    {
        return (*data);
    }
    T* operator->()
    {
        return data;
    }
    T* change()
    {
        T* tmpPtr = data;
        data = NULL;
        return  tmpPtr;
    }
    ~AutoPtr()
    {
      
        if (data)
            delete data;
        data = NULL;
    }
};

int main()
{
    AutoPtr<int>pointer1(new int(2));
    AutoPtr<int> pointer2 = pointer1;
    *pointer2 = 4;
    cout << *pointer2 << endl;

    AutoPtr<std::string> pointer4(new std::string("Hello world"));
    AutoPtr<std::string> pointer5 = pointer4;
    std::cout << *pointer5 << std::endl;
    AutoPtr<double> pointer6(new double(6.45));
    AutoPtr<double> pointer7 = pointer6;
    std::cout << *pointer7 << std::endl;
}