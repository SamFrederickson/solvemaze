//LinkedList.h
//Samuel Frederickson
// Linked List Class for Stack File

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class LinkedList
{
private:

  struct node
  {
     int x; // x coordinate of array
     int y; // y coordinate of array
     node * next;
  };

  typedef node * nodeptr;

  nodeptr head;
  int count;

public:

   LinkedList()
   {
      head = NULL;
      count = 0;
   }

   ~LinkedList()
   {
      nodeptr p = head, n;
 
      while (p != NULL)
      {
         n = p;
         p = p->next;
         delete n;
      }
   }
    // Add a node onto the front of the linked list.
   void AddNode(int x, int y);

    // Delete the first node found with the value x, if one exists.
   void DeleteNode();

   // Output the values in the nodes, one integer per line. 
   void PrintNodes();

   //outputs the first node
   void FirstNode(int &a, int &b);

   // Gets size of the array
   int Size();

};
#endif
