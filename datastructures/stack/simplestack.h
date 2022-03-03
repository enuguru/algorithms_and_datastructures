

// simplestack.h: header file
template< class Typ, int MaxStack >
class Stack {
   int EmptyStack;
   Typ items[MaxStack];
   int top;
public:
   Stack();
   ~Stack();
   void push(Typ);
   Typ pop();
   int empty();
   int full();
};
