#include <vector>
#include <iostream>
using namespace std;
class A{
public:
    void test() const{
        cout<<"Ac"<<endl;
    }
    void test(){
        cout<<"A"<<endl;
    }
    virtual ~A(){}
};
class B : public A{
    void test(){
        cout<<"B"<<endl;
    }
};
int main()
{
    const A* a = new B();
    a->test();
    delete a; 
}
int calPoints(vector<string>& operations) {
    string s[1005];
    int i = 0;
    for(auto temp = operations.begin(); temp !=operations.end() ; temp++)
    {
        if(*temp == "+")
        {
            s[i] = s[i-1] + s[i-2];
            i++;
        }
        
    }
}