#ifndef SPLIT_H
#define SPLIT_H


struct Node 
{
  int value;
  Node* next;

  /**
   * Initializing constructor
   */
  Node(int v, Node* n)
  {
    value = v;
    next = n;
  }
};

void split(Node*& in, Node*& odds, Node*& evens);
void splitHelper(Node* in, Node* oddsCurrent, Node* evensCurrent, Node*& oddsHead, Node*& evensHead);

#endif
