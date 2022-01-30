
#include<iostream> 

template <typename T>
class UniquePtr {
    T* data;
public:
    UniquePtr(T* p)
    {
        data = p;
    }

    UniquePtr(const UniquePtr& dataRhs) = delete;

    UniquePtr(UniquePtr&& dataRhs)
    {
        data = std::move(dataRhs.data)noexcept;
       dataRhs.data = NULL;
    }
    UniquePtr& operator=(const UniquePtr& dataRhs) = delete;
    UniquePtr& operator=(UniquePtr&& dataRhs)
    {
        data = std::move(dataRhs.data)noexcept;

        dataRhs.data = NULL;
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
    ~UniquePtr()
    {
        if (data)
            delete data;
        data = NULL;
    }
};

int main()
{
    UniquePtr<int> pointer1 = new int(2);
    UniquePtr<int>pointer2 = std::move(up1)noexcept;
    *up2 = 9;
    std::cout << *pointer2 << std::endl;

   
 
}
