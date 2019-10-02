//Samuel Frederickson
//9/29/2019
//CS-121
//stack.cpp

#include <iostream>
#include "Stack.h"
#include "LinkedList.h"
using namespace std;

Stack::Stack()
{
}


Stack::~Stack()
{
   //delete topPtr;
   while( !IsEmpty() ) {
       topPtr.DeleteNode( );
   }
}

void Stack::Push(int n, int l)
{
   topPtr.AddNode( n, l );
}


void Stack::Pop(int &x, int &y)
{
    assert(!IsEmpty());
    topPtr.FirstNode(x, y);
    topPtr.DeleteNode();
}

int Stack::IsEmpty()
{
    int n = topPtr.Size();
    return (n == 0);
}


void Stack::Print()
{
    topPtr.PrintNodes();
}


