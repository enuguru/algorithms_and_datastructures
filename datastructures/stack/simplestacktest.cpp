

// simplestacktest.cpp: use templated stack
#include <iostream>
#include "simplestack.h"
using namespace std;


// stack.cpp: function definitions

template< class Typ, int MaxStack >
Stack< Typ, MaxStack >::Stack() {
   EmptyStack = -1;
   top = EmptyStack;
}

template< class Typ, int MaxStack >
Stack< Typ, MaxStack >::~Stack()
{  delete[] items; }

template< class Typ, int MaxStack >
void Stack< Typ, MaxStack >::push(Typ c)
{  items[ ++top ] = c; }

template< class Typ, int MaxStack >
Typ Stack< Typ, MaxStack >::pop()
{  return items[ top-- ]; }

template< class Typ, int MaxStack >
int Stack< Typ, MaxStack >::full()
{  return top + 1 == MaxStack; }

template< class Typ, int MaxStack >
int Stack< Typ, MaxStack >::empty()
{  return top == EmptyStack; }


int main() {
   Stack<char, 10> s; // 10 chars
   char ch;
   while ((ch = cin.get()) != '\n')
      if (!s.full()) s.push(ch);
   while (!s.empty())
      cout << s.pop();
   cout << endl;
   Stack<double, 4> ds; // 4 doubles
   double d[] =
      {1.0, 3.0, 5.0, 7.0, 9.0, 0.0};
   int i = 0;
   while (d[i] != 0.0 && !ds.full())
      if (!ds.full()) ds.push(d[i++]);
   while (!ds.empty())
      cout << ds.pop() << "  ";
   cout << endl;
   return 0;
}
