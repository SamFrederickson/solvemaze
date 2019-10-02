//LinkedList.cpp
//Samuel Frederickson
//9/27/2019
#include <iostream>
#include "LinkedList.h"
using namespace std;

//  Add an item to the FRONT of the list
void LinkedList::AddNode( int x, int y )
{
    nodeptr n;

        //  allocate new node
    n = new node;
    n->x = x;
    n->y = y;
    count++;

    if( head == NULL )
    {
        head = n;
        n->next = NULL;
    }
    else
    {
        nodeptr tmp = head;
        n->next = tmp;
        head = n;
    }
}
//from front
void LinkedList::DeleteNode()
{
    nodeptr p = head;
    
    if(p == NULL)  
    {
        cout << "Nothing to delete" << endl; // do nothing
    }
    else
    {
        head = p->next;  //update head

        p->next = NULL; //break
        delete p;
        count--;
    }
}

void LinkedList::PrintNodes()
{
    nodeptr p = head;

    while( p != NULL )
    {
        cout << p->x << "," << p->y << endl;
        p = p->next;
    }
}

void LinkedList::FirstNode(int &a, int &b)
{
    a = head->x;
    b = head->y;
}

int LinkedList::Size()
{
    return count;
}