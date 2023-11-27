#include<iostream>
using namespace std;

class sample
{
    public:
        int a, b;

    public:
        sample(int a, int b)
        {
            this-> a = a;
            this-> b = b;
        }
        sample(sample & old)
        {
            a = old.a;
            b = old.b;
        }
        void print()
        {
            cout<< "a = "<< a << endl;
            cout<< "b = "<< b << endl;
        }
};
int main()
{
    sample s1(10, 20);
    sample s2(s1);
    s1.print();
    s2.print();

    return 0;
}

