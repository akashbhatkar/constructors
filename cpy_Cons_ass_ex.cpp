// tried copy constructor and copy assignment operator
#include <iostream>

using namespace std;
class overload
{
    int i;
    int *p;
    public: 
    overload(int a):i(a)
    {
        // cout<<"i="<<i<<endl;
        cout<<"constructor"<<endl;
        p=new int[i];
    }
    
    overload(const overload& obj)
    {
        
        cout<<"copy constructor"<<endl;
        i=obj.i;
        cout<<"i="<<i<<endl;
        if(p!=nullptr)
        {
            p=new int[i];
            for(int j=0;j<i;j++)
            {
                this->p[i]=obj.p[i];
            }
        }
        else 
        p=nullptr;
    }
    overload & operator=(const overload& obj2)
    {
        cout<<"copy assignment operator"<<endl;
        if(this==&obj2)
        {
            cout<<"assignning to the same object";
        }
        else 
        {
            i=obj2.i;
             cout<<"i="<<i<<endl;
            if(p!=nullptr)
            {
                p=new int[i];
                for(int j=0;j<i;j++)
                {
                    this->p[i]=obj2.p[i];
                    
                }
            }
            else 
            p=nullptr;
        }
    }
    
    
};
int main()
{
    overload obj(10);
    overload obj2(20);
    overload obj1(obj2);
    obj2=obj2;
}