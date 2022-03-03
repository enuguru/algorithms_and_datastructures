

//The following program shows OOP style technique to create queue buffer (FIFO) using class template  
 
#include<iostream>
#include<cstdlib>
#define default_value 16
using namespace std;
 
template< class T > class Queue
{
    public:
        Queue(int = default_value);//default constructor
        ~Queue()//destructor
          {delete [] values;}
        bool enQueue( T );
        T deQueue();
        bool isEmpty();
        bool isFull();
    private:
        int size;
        T *values;
        int front;
        int back;
};
 
template< class T > Queue<T>::Queue(int x):
    size(x),//ctor
    values(new T[size]),
    front(0),
    back(0)
      { /*empty*/  }
 
template< class T > bool Queue<T>::isFull()
{
    if((back + 1) %  size == front )
        return 1;
    else
        return 0;
}
 
template< class T > bool Queue<T>::enQueue(T x)
{
    bool b = 0;
   if(!Queue<T>::isFull())
   {
       values[back] = x;
       back = (back + 1) % size;
       b = 1;
   }
  return b;
}
 
template< class T > bool Queue<T>::isEmpty()
{
    if( back  == front )//is empty
        return 1;
    else
    return 0; //is not empty
}
 
template< class T > T Queue<T>::deQueue()
{
    T val = -1;
    if(!Queue<T>::isEmpty())
    {
        val = values[front];
        front = ( front + 1 ) % size;
    }
    else
    {
        cerr << "Queue is Empty : ";
    }
return val;
 
}
 
int main()
{
        Queue <float> qu1(32);
        float x = 1.1;
        int i = 1; //declare software counter i
    cout << "\n EnQueued values into qu1: ";
 
    for(   ; i < 10 ; i++) //start enter 10 elements into Qu1 object
        {
            if(qu1.enQueue(i*x))
                cout << endl << i*x;
            else
                cout << "\n Queue (qu1) is full: ";
        }
        cout << "\n\n DeQueued values from qu1 : \n";
    for(int j = 1 ; j < 10 ; j++)
          cout << qu1.deQueue() << endl;
 
    cout << endl << endl;
    return 0;
}
