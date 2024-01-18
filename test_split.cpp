/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

using namespace std;

void printAllNodesAndDelete(Node* head);

int main(int argc, char* argv[])
{
    Node* in = new Node(1, nullptr);
    Node* start = in;
    
    in->next = new Node(2, nullptr);
    in = in->next;
    in->next = new Node(3, nullptr);
    in = in->next;
    in->next = new Node(4, nullptr);
    in = in->next;
    in->next = new Node(5, nullptr);
    in = in->next;
    in->next = new Node(6, nullptr);
    
    in = start;
    
    Node* odds = nullptr;
    Node* evens = nullptr;
    
    split(in, odds, evens);
    
    cout << "Test: " << evens->value << endl;
    
    
    cout << odds->value << " ";
    cout << odds->next->value << " ";
    cout << odds->next->next->value << " ";
    cout << odds->next->next->next->value << endl;
    cout << endl;
    printAllNodesAndDelete(evens);
}

void printAllNodesAndDelete(Node* head)
{
    // cout << "Ran" << endl;
    if (head == nullptr) return;
    cout << head->value << endl;
    printAllNodesAndDelete(head->next);
    delete head;
}
