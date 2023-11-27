#include<iostream>
using namespace std;

class A
{
    public:
        void fun() {
            cout<< "Hello Rohit Kuhar"<< "\n";
        }
        
        //can't overload a function with change in return type 
        /*int fun() {
            cout<< "Hello Rohit kuhar"<< "\n";
            return 0;
        }
        */

        void fun(string name) {
            cout<< "Hello "<< name << "\n";
        }

        //Can't overload a function with change in input
        /*int fun() {
            cout<<"Hello"<<"\n";
            return 0;
        }
        */
        
        void fun(int x, int y, int z = 0, int v = 0, int w = 0) {
            cout<< x+y+z+v+w << endl;
        }

};

int main() {
    A obj;
    obj.fun();
    obj.fun("Rahul Kuhar");
    obj.fun(1,2,3);
    obj.fun(11,22,33,44);
    obj.fun(10,20,12,23,40);

    return 0;
}
