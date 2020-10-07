#include <iostream>
#include <cassert>
#include <vector>

//Struct
struct Node {
    int value;
    Node* previous;
    Node* next;
};

//Class
class LinkedList {

  private:
    //Two node pointers
    Node* head;
    Node* tail;
    size = 0;


  public:
    //Constructor
    LinkedList() {
      //Assigning random value 0 to head and tail
      head = new Node(0, nullptr, nullptr);
      tail = new Node(0, nullptr, nullptr);
      head->next = tail;
      tail->previous = head;
      }

    int length() {
    return size;
  }

void append(int val){
  Node* a = new Node(val, tail->previous, tail);
  tail->previous = a;
  a->previous->next = a;
  size++;
  }

void print() {
    Node* current = head->next;
    cout << "[";
    while (current->next != nullptr) {
        cout << current->value;
        cout << ", ";
        current = current->next;
    }
    //while (current != tail:)
    cout << current->value << "]" << endl;
}

~LinkedList() {
    Node* current;
    Node* previous;
    Node* next;

    current = head;

    while (current != nullptr) {
        previous = current->previous;
        next = current->next;
        delete current;
        current = previous;
        current = next;
    }


int& operator[] (int index) {
  Node* current = head->next;

  for (int i=0; i<index; i++) {
    current = current->next;
    }
    return current;
    }

}
void insert(int val, int index) {
    Node* previous = get_node(index-1);
    Node* next = prev->next;
    prev->next = new Node(val, next);
}

};
