#include<iostream>
using namespace std;
/*
��д�������캯��Ĭ��ǳ�����������¶��󣬿���ֵ
*/
class Student{
public:
    Student(){
        a = new int[5];
        cout<<"�����˹��캯��"<<endl;
    }
    ~Student(){
        delete[] a;
        cout<<"��������������"<<endl;
    }
    void print(){
        cout<<"a����ĵ�ַ��"<<&a<<endl;
        cout<<"aָ���ڴ�ĵ�ַ��"<<a<<endl;
        cout<<"p����ĵ�ַ��"<<&p<<endl;
    }
private:
    int* a;
    int p;
};
class Teacher{
public:
    Teacher(){
        a = new int[5];
        cout<<"�����˹��캯��"<<endl;
    }
    ~Teacher(){
        delete[] a;
        cout<<"��������������"<<endl;
    }
    Teacher(const Teacher& other){
        this->a = new int[5];
        /*�������дһ�´��룬
        �����ڴ�ռ��ֵ���ƹ�����
        ��ע�����ǵ��ڴ��ַ���ˣ�
        �����ǿ����Ķ��󲢲���ͬһ����
        ��Ϊ��������new��
        */
        this->p = other.p;
    }
    void print(){
        cout<<"a����ĵ�ַ��"<<&a<<endl;
        cout<<"aָ���ڴ�ĵ�ַ��"<<a<<endl;
        cout<<"p����ĵ�ַ��"<<&p<<endl;
    }
private:
    int* a;
    int p;
};
/*
ǳ��������~test1()
�������ǻᷢ�����͵�ַ����ͬ,�����ǵ�ֵ��һ��
��ᵼ��ĳЩ����
���磺
����������һ�������ʱ��Ϊ�˱�֤�ڴ氲ȫ��
���ǻ�����ڶ���������ڴ��ͷŵ�����͵�����һ���޴�����⣬
���Ƿ��ڴ��ʱ�򣬷�����һ�������Ķ����Ѿ������ͷŵ���
�����ǿ϶��ᱨ��
ͬʱ�أ������޸�a�ڴ�ռ�Ķ�������һ��������a��Ҳ��ı�
���Ե�����ǳ������ʱ��
һ��Ҫ�������Щ����/ָ��(��Ȼ���û��ָ��Ͳ���Ҫ������),
��������Ҫ�Ƕ����Բ����������
������������ֻ��ָ��shared_ptr
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
