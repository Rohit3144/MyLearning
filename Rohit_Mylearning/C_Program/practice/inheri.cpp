#include<iostream>
using namespace std;

class Human
{
    public:
        int height, weight, age;

    public:
        int getAge()
        {
            return this-> age;
        }
        void setWeight(int w)
        {
            cout<<"This is setWeight() in Human class"<< endl;
            this->weight = w;
        }
        
};

class Male: public Human
{
    public:
        string color;

        void sleep()
        {
            cout<< "Male is sleeping" << endl;
        }
};

int main()
{
    Male obj;
    cout<< obj.height << endl;
    cout<< obj.weight << endl;
    cout<< obj.age << endl;

    cout<< obj.color<< endl;
    obj.sleep();
    obj.setWeight(100);
    cout<< obj.weight<< endl;

    return 0;
}
