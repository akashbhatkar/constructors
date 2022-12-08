// Move constructor and move assignment operator 

#include <iostream>

using namespace std;
class A
{
    int len;
    int *data;
public:
    A(int size)
    {
        cout<<"default Constructor"<<endl;
        len=size;
        data=new int[size];
    }
    //move constructor
    A(A&& obj)
    {
        len=obj.len;
        data=obj.data;
        cout<<"move constructor"<<endl<<"len="<<len<<endl;
        obj.data=nullptr;
        obj.len=0;
    }

    //move assignment operator
    A& operator =(A&& obj)
    {
        len=obj.len;
        data=obj.data;
        cout<<"move assignment"<<endl<<"len="<<len<<endl;
        obj.data=nullptr;
        obj.len=0;
        return obj;
    }
};

int main()
{
    A obj(10);
    A obj2(move(obj));
    A obj3(25);
    obj=move(obj3);
}
