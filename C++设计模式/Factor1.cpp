#include<iostream>
using namespace std;
class Proudctor{
public:
    virtual ~Proudctor(){}
    virtual string someop() const = 0;
};
class concreteProductorA :public Proudctor{
public:
    string someop() const override{
        return "A";
    }
};
class concreteProductorB :public Proudctor{
public:
    string someop() const override{
        return "B";
    }
};
class creator{
public:
virtual ~creator() {}
virtual Productor* FactoryMethod() const = 0;
string dosomeop(){
    Proudctor* pro = this->FactoryMethod();
    string res = pro->someop();
    delete pro;
    retrun res;
}
};
class concreteCreatorA : public creator{
    Proudctor* FactoryMethod() const override{
        return new concreteProductorA();
    }
};
class concreteCreatorB : public creator{
    Proudctor* FactoryMethod() const override{
        return new concreteProductorB();
    }
};
