#include <iostream>
#include <cassert>
#include <vector>

//Struct
struct Node {
    int value;
    Node* previous;
    Node* next;
};

//Constructor
Node(int k, Node* p, Node* n) {
    value = k;
    previous = p;
    next = n;
}

//Class
class LinkedList {
  private:
    //If empty list point to nullptr
    head = nullptr;

    //Two node pointers
    Node* head;
    Node* tail;

  public:
    int length() {
    Node* current = head;
    int count = 0;
    while (current != nullptr) {
        count++;
        current = current->next;
      }
      return count;
    }

void append(int){}


void print(){}


};
