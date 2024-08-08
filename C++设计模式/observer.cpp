#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <string>
using namespace std;
class IObserver{
public:
    virtual ~IObserver(){}
    virtual void update(const string& message_form_subject) = 0;
    
};
class ISubject {
public:
    virtual ~ISubject(){}
    virtual void attach(shared_ptr<IObserver> observer) = 0;
    virtual void detach(shared_ptr<IObserver> observer) = 0;
    virtual void notify() = 0;
};
class subject : public ISubject{
private:
    list<shared_ptr<IObserver>> mListObservers;
    string mmessage;
public:
    virtual ~subject(){}
    void attach(shared_ptr<IObserver> observer) override{
        mListObservers.push_back(observer);
    }
    void detach(shared_ptr<IObserver> observer) override{
        mListObservers.remove(observer);
    }
    void notify() override{
        for (auto &observer : mListObservers)
        {
            observer->update(mmessage);
        }
    }
    void createMessage(const string& message){
        mmessage = message;
        notify();
    }
};
class observer : public IObserver{
private:
    string mMessageFromSubject;
    shared_ptr<ISubject> mSubject;
    static int mStaticNumber;
    int mNumber;
public:
    observer(shared_ptr<ISubject> subject) : mSubject(subject){
        this->mNumber = mStaticNumber;
        mSubject->attach(make_shared<observer>(*this));
    }
    virtual ~observer(){}
    void update(const string& message_from_subject) override{
        mMessageFromSubject = message_from_subject;
        cout<< "observer "<<mNumber<<" get message "<<mMessageFromSubject<<endl;
    }
    void removeMeFromTheList(){
        mSubject.get()->detach(make_shared<observer>(*this));
    }
};
int observer::mStaticNumber = 2;

void clientCode() {
    shared_ptr<subject> rSubject = shared_ptr<subject>(new subject());
    shared_ptr<observer> rObserver1 = shared_ptr<observer>(new observer(rSubject));
    shared_ptr<observer> rObserver2 = shared_ptr<observer>(new observer(rSubject));
    rSubject.get()->createMessage("hello");
    rObserver1.get()->removeMeFromTheList();
}
int main(){
    clientCode();
}