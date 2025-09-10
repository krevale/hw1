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

void deallocateList(Node* in);

int main(int argc, char* argv[])
{

  Node* head = new Node(1, nullptr);
  Node* list = head;

  cout << "Starting list: ";

  for (int i = 2; i < 17; ++i) {
    head->next = new Node(i, nullptr);
    head = head->next;
  }

  head = list;

  while (head != NULL) {
    cout << head->value << ", ";
    head = head->next;
  }

  cout << endl << endl;

  Node* oddList = nullptr;
  Node* evenList = nullptr;

  split(list, oddList, evenList);

  cout << "Odds: ";

  head = oddList;

  while (head != NULL) {
    cout << head->value << ", ";
    head = head->next;
  }

  cout << endl;

  cout << "Evens: ";

  head = evenList;

  while (head != NULL) {
    cout << head->value << ", ";
    head = head->next;
  }

  cout << endl;

  deallocateList(oddList);
  deallocateList(evenList);
}

void deallocateList(Node* in) {
  while (in != NULL) {
    Node* temp = in;
    in = in->next;
    delete temp;
  }
}