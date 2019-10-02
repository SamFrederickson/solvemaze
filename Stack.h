//Stack.h
//Samuel Frederickson
//9/27/2019
 
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "LinkedList.h"
#include <assert.h>


class Stack {
public:
   Stack();
   ~Stack();

   void Push(int n, int l);     // push item onto stack
   void Pop(int &x, int &y);            // remove item from stack
   int IsEmpty();        // is the stack empty?
   void Print();         // print the stack

private:
   LinkedList topPtr;   // pointer to list
   LinkedList v;  //List of visited nodes
};

#endif
