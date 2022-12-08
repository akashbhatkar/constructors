// WAP to demonstrate the use of copy constructor and copy assignment operator 

#include <iostream>
using namespace std;



class MyClass
{
   public:
   int Size;
   int* Data;
   
   MyClass(int s)
   : Size(s)
   , Data(new int[Size])
   {
       Data[0] = 10;
   }
   
   // Copy Constructor
  MyClass(const MyClass& obj)
  : Size(obj.Size)
  {
      
      if(obj.Data != nullptr)
      {
         Data = new int[obj.Size];
         for(int i = 0; i < Size; ++i)
         {
            this->Data[i] = obj.Data[i];
         }
      }
      else
      {
          Data = nullptr;
      }
  }
  
  // copy assignment operator
  MyClass& operator = (const MyClass& obj)
  {
      
      cout << "Copy Assignment op" << endl;
      if(this == &obj)
      {
           cout << "Copy Assignment op -------- SAME ADDRESS" << endl;
          return *this;
      }
      
      delete[] Data;
      
      Size = obj.Size;
      
      if(obj.Data != nullptr)
      {
         Data = new int[obj.Size];
         for(int i = 0; i < Size; ++i)
         {
            this->Data[i] = obj.Data[i];
         }
      }
      else
      {
          Data = nullptr;
      }
      return *this;
  }
  
  
  
};



int main()
{
    MyClass obj1(12);

    MyClass obj2 = obj1;
    
    obj2 = obj1;

    return 0;
}
