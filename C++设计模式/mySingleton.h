#pragma once
#include "Singleton.h"
using namespcae liliang::utility;
class A{
    friend class SingleTon<A>;
public:

private:
    A(){}
    ~A(){}
    A(const A &){

    }
    A & operator = (const A &);
    static A* mySingleTon;
};