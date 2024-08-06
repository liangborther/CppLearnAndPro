#include <iostream>
#include <memory>
#include <string>
using namespace std;
class component{
    public:
    virtual ~component(){}
    virtual string operation() const = 0;

};
class concreteComponent : public component
{
public:
    string operation() const override{
        return "concreteComponent ";
    }
};

class decorator : public component{
protected:
    component *mComponent;
public:
    decorator(component *component) : mComponent(component){}
    virtual ~decorator(){}
    string operation() const override{return mComponent->operation();}
};

class concreteDecoratorA : public decorator{
public:
    concreteDecoratorA(component* component) : decorator(component){}
    string operation() const override{
        return decorator::operation() + "concreteDecoratorA ";
    }
};

class concreteDecoratorB : public decorator{
public:
    concreteDecoratorB(component* component) : decorator(component){}
    string operation() const override{
        return decorator::operation() + "concreteDecoratorB ";
    }
};
void clientCode(shared_ptr<component> component){
    cout << component->operation()<<endl;
}
int main(){
    auto simple = shared_ptr<component>(new concreteComponent());
    clientCode(simple);
    cout<<"\n\n";
    auto decorator1 = shared_ptr<component>(new concreteDecoratorA(simple.get()));
    auto decorator2 = shared_ptr<component>(new concreteDecoratorB(decorator1.get()));
    auto decorator3 = shared_ptr<component>(new concreteDecoratorB(decorator2.get()));
    clientCode(decorator3);
}