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
};
