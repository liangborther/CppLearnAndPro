#include<iostream>
using namespace std;
/*
不写拷贝构造函数默认浅拷贝，生成新对象，拷贝值
*/
class Student{
public:
    Student(){
        a = new int[5];
        cout<<"调用了构造函数"<<endl;
    }
    ~Student(){
        delete[] a;
        cout<<"调用了析构函数"<<endl;
    }
    void print(){
        cout<<"a本身的地址："<<&a<<endl;
        cout<<"a指向内存的地址："<<a<<endl;
        cout<<"p本身的地址："<<&p<<endl;
    }
private:
    int* a;
    int p;
};
class Teacher{
public:
    Teacher(){
        a = new int[5];
        cout<<"调用了构造函数"<<endl;
    }
    ~Teacher(){
        delete[] a;
        cout<<"调用了析构函数"<<endl;
    }
    Teacher(const Teacher& other){
        this->a = new int[5];
        /*这里可以写一下代码，
        把它内存空间的值复制过来，
        但注意我们的内存地址变了，
        和我们拷贝的对象并不是同一个，
        因为我们重新new了
        */
        this->p = other.p;
    }
    void print(){
        cout<<"a本身的地址："<<&a<<endl;
        cout<<"a指向内存的地址："<<a<<endl;
        cout<<"p本身的地址："<<&p<<endl;
    }
private:
    int* a;
    int p;
};
/*
浅拷贝测试~test1()
这里我们会发现类型地址都不同,但他们的值都一致
这会导致某些错误：
比如：
我们在析构一个对象的时候，为了保证内存安全，
我们会把他在堆中申请的内存释放掉，这就导致了一个巨大的问题，
我是放内存的时候，发现上一个析构的对象已经帮我释放掉了
那我们肯定会报错
同时呢，我们修改a内存空间的东西，另一个对象中a的也会改变
所以当我们浅拷贝的时候，
一定要处理好这些引用/指针(当然如果没有指针就不需要考虑了),
如果真的需要是都可以操作这个对象，
不妨可以试试只能指针shared_ptr
*/
void test1(){
    Student s1;
    Student s2 = s1;
    s1.print();
    s2.print();
}
int main(){
    Teacher s1;
    Teacher s2 = s1;
    s1.print();
    s2.print();
}
