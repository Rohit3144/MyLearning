#include<iostream>
using namespace std;

class test
{
    int a;

    public:
    void gett()
    {
        cin >> a;
    }
    test()
    {
    }
    test(test &t)
    {
        //this->a = 4;
        cout << "Called Copy Constructor this->a => " << this->a << "\t t.a => " << t.a << endl;
    }
    void operator==(test &tt)
    {
        if(a == tt.a)
            {
                cout<<"objects are equal a => "<< a << " tt.a => " << tt.a <<  endl;
            }
        else
            {
                cout<<"objects are not equal a => "<< a << " tt.a => " << tt.a <<  endl;
            }
    }
};

int main()
{
    test t1, t;
    t1.gett();
    t.gett();
    
    t1 == t;

    return 0;
}
