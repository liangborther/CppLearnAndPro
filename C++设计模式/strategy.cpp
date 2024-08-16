#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
class strategy{
public:
virtual ~strategy(){}
virtual string doAlgorithm(const vector<string> &v) = 0;
};

class context{
private:
shared_ptr<strategy> mStrategy;
public:
context(shared_ptr<strategy> strategy) : mStrategy(strategy){}
~context(){}
void setStrategy(shared_ptr<strategy> strategy){
    mStrategy.reset();
    this->mStrategy = strategy;
}
void doSomeBusinessLogic() const{
    cout<<mStrategy.get()->doAlgorithm({"x","b","c"})<<endl;
}
};

class concreteStrategyA : public strategy{
public:
    string doAlgorithm(const vector<string>& v) override{
        string res ="";
        for_each(v.begin(),v.end(),[&res](const string& s) {res += s;});
        return res;
    }
};

class concreteStrategyB : public strategy{
public:
    string doAlgorithm(const vector<string>& v) override{
        string res ="";
        for_each(v.begin(),v.end(),[&res](const string& s) {res += s;});
        sort(res.begin(),res.end());
        return res;
    }
};

void clientCode(){
    shared_ptr<strategy> strategyA = make_shared<concreteStrategyA>();
    shared_ptr<strategy> strategyB = make_shared<concreteStrategyB>();
    shared_ptr<context> contextA = make_shared<context>(strategyA);
    shared_ptr<context> contextB = make_shared<context>(strategyB);
    contextA.get()->doSomeBusinessLogic();
    contextB.get()->doSomeBusinessLogic();
}
int main(){
    clientCode();
}