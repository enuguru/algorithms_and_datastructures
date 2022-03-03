

#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include "Exception.h"

template <class T>
class Stack {
    public:
        Stack():top(0) {
            std::cout << "In Stack constructor" << std::endl;
        }
        ~Stack() {
            std::cout << "In Stack destructor" << std::endl;
            while ( !isEmpty() ) {
                pop();
            }
            isEmpty();
        }

        void push (const T& object);
        T pop();
        const T& topElement();
        bool isEmpty();

    private:
        struct StackNode {              // linked list node
            T data;                     // data at this node
            StackNode *next;            // next node in list

            // StackNode constructor initializes both fields
            StackNode(const T& newData, StackNode *nextNode)
                : data(newData), next(nextNode) {}
        };

        // My Stack should not allow copy of entire stack
        Stack(const Stack& lhs) {}

        // My Stack should not allow assignment of one stack to another
        Stack& operator=(const Stack& rhs) {}
        StackNode *top;                 // top of stack

};

template <class T>
void Stack<T>::push(const T& obj) {
    std::cout << "In PUSH Operation" << std::endl;
    top = new StackNode(obj, top);
}

template <class T>
T Stack<T>::pop() {
    std::cout << "In POP Operation" << std::endl;
    if ( !isEmpty() ) {
        StackNode *topNode = top;
        top = top->next;
        T data = topNode->data;
        delete topNode;
        return data;
    }
    throw StackException ("Empty Stack");
    //return 0;
}

template <class T>
const T& Stack<T>::topElement() {
    std::cout << "In topElement Operation" << std::endl;
    if ( !isEmpty() ) {
        return top->data;
    }
}

template <class T>
bool Stack<T>::isEmpty() {
    if (top == 0) {
        return true;
    }
    else {
        return false;
    }
}

#endif 
