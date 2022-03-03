

// stack.cpp: function definitions
#include "simplestack.h"

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
