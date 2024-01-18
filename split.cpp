/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

#include <iostream>

using namespace std;

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
    if (in == nullptr) return;
    
    // If the value is even
    if (in->value % 2 == 0) evens = in;
    else odds = in;
    
    splitHelper (in->next, odds, evens, odds, evens);
    
    in = nullptr;
}

/* If you needed a helper function, write it here */
void splitHelper(Node* in, Node* oddsCurrent, Node* evensCurrent, Node*& oddsHead, Node*& evensHead)
{
    if (in == nullptr) return;
    
    cout << in->value;
    if (in->value % 2 == 0)
    {
        cout << " is even." << endl;
        if (evensCurrent == nullptr)
        {
            evensHead = in;
            evensCurrent = in;
            splitHelper(in->next, oddsCurrent, evensCurrent, oddsHead, evensHead);
        }
        else
        {
            evensCurrent->next = in;
            splitHelper(in->next, oddsCurrent, evensCurrent->next, oddsHead, evensHead);
        }
        
    }
    else
    {
        cout << " is odd." << endl;
        if (oddsCurrent == nullptr)
        {
            oddsHead = in;
            oddsCurrent = in;
            splitHelper(in->next, oddsCurrent, evensCurrent, oddsHead, evensHead);
        }
        else
        {
            oddsCurrent->next = in;
            splitHelper(in->next, oddsCurrent->next, evensCurrent, oddsHead, evensHead);
        }
    }
}
