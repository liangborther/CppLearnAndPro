#include <iostream>
using namespace std;
class Productor{
public:
    virtual ~Productor() {}
    virtual string operation() const = 0;
};
class ConcreteProductA :public Productor{
public:
    string operation() const override{
        return "ConcreteProductA";
    }
};
class ConcreteProductB :public Productor{
public:
    string operation() const override{
        return "ConcreteProductB";
    }
};
class Creator{
    public:
    virtual ~Creator(){}
    virtual Productor* FactoryMethod() const = 0;
    string SomeOperation() const{
        Productor *Product = this->FactoryMethod();
        string result = Product->operation();
        delete Product;
        return result;
    }
};
class ConcreteCreatorA : public Creator{
public:
    Productor* FactoryMethod() const override{
        return new ConcreteProductA();
    }
};
class ConcreteCreatorB : public Creator{
public:
    Productor* FactoryMethod() const override{
        return new ConcreteProductB();
    }
};
void ClientCode(const Creator& creator){
    cout<< creator.SomeOperation()<<endl;
}
int main(){
    Creator* creator1 = new ConcreteCreatorA();
    ClientCode(*creator1);
    Creator* creator2 = new ConcreteCreatorB();
    ClientCode(*creator2);
    delete creator1;
    delete creator2;
}
