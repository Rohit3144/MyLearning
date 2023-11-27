#include<iostream>
using namespace std;

class A
{
    public:
        void fun() 
        {
            cout<<"I am A" <<"\n";
        }
};
class B
{
    public:
        void fun() 
        {
            cout<<"I am B" <<"\n";
        }
};
class C: public A, public B
{
    public:
        void f()
        {
            cout<<"This is class C"<<"\n";
        }
};
int main()
{
    C obj;

    //Below line will give the ambiguity error 
    //obj.fun();
    
    obj.A::fun();
    obj.B::fun();
    obj.f();

    return 0;
}
