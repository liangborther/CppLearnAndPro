#pragma once

namespace liliang{
namespace utility{
template<typename T>
class SingleTon{
private:
    SingleTon();
    SingleTon(const SingleTon<T> &);
    ~SingleTon();
    SingleTon<T>& operator = (const SingleTon<T>);

    static T* myInstance;
public:
    static T* Instacne(){
        if(myInstance == NULL)
        {
            myInstance == new T();
        }
        return myInstance;
    }
};
template<typename T>
T * SingleTon<T>::myInstance = NULL;
}
}