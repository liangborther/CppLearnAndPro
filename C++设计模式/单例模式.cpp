#include<iostream>
using namespace std;
class sig{
private:
sig(){}
sig(const sig&) = delete;
~sig(){}
sig & operator = (const sig)= delete;
static sig* mySig;
public:
static sig* instance(){
    if(mySig == nullptr){
        return new sig();
    }else{
        return mySig;
    }
}
};
sig* sig::mySig = nullptr;
int main(){
    sig* p = sig::instance();
    cout<<p<<endl;
}