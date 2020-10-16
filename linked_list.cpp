#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include  <stdexcept>

using namespace std;

//Struct

struct Node {
    int value;
    Node* previous;
    Node* next;

    //Node constructor
    Node(int n) {
    next = nullptr;
    previous = nullptr;
    value = n;
    }
};

//Class
class LinkedList {

  private:
    //Two node pointers
    Node* head;
    Node* tail;
    int size;


  public:
    //Constructor
    LinkedList() {
      head = nullptr;
      tail = nullptr;
      size = 0;
      }

    int length() {
      return size;
  }

void print() {
    Node* current = head;
    cout << "[";

    while (current->next!= nullptr) {
        cout << current->value;
        cout << ", ";
        current = current->next;
      }
    cout << current->value << "]" << endl;
}

//Destructor
~LinkedList() {
    Node* current;

    for(current = head; current != nullptr; current=current->next) {
        delete[] current;
    }

}

int& operator[] (int index) {
  if (index < 0 or index >= size) {
        throw std::range_error("IndexError: Index out of range");
      }

  Node* current = head;

  for (int i=0; i<index; i++) {
    current = current->next;
    }
    return current->value;
}

void append(int val){
  Node* a = new Node(val);
  if(head == nullptr){
    head = a;
    tail = a;
    size++;
  }
  else{
  tail->next = a;
  a->previous = tail;
  tail = a;
  size++;
  }
}

void insert(int val, int index){
  if (index < 0 or index >= size) {
        throw std::range_error("IndexError: Index out of range");
      }
  Node* current = head;
  for(int i = 0; i<index; i++){
    current = current->next;
  }
  Node* a = new Node(val);
  Node* left = current->previous;
  Node* right = current;

  a->previous = left;
  a->next = right;

  left->next = a;
  right->previous = a;

  size++;
}

void remove(int index){
  if (index < 0 or index >= size) {
        throw std::range_error("IndexError: Index out of range");
      }
  Node* current = head;
  if(index == size-1){
    current = tail;
    Node* left = current->previous;
    delete[] current;
    size--;
    tail = left;
    tail->next = nullptr;
  }
  else if(index == 0){
    current = head;
    Node* right = current->next;
    delete[] current;
    size--;
    head = right;
    head->next = right->next;
  }
  else{
    for(int i=0; i<index; i++){
      current = current->next;
    }
    Node* left = current->previous;
    Node* right = current->next;
    left->next = right;
    right->previous = left;
    delete[] current;
    size--;
  }
}


int pop(int index) {
  Node* current = head;
  for(int i=0; i<index; i++)
{
  current = current->next;
}
  int pop_value = current->value;
  remove(index);
  return pop_value;

}

int pop(){
  return pop(size-1);
}

//Overload constructor
LinkedList(vector<int> initial) {
    size = 0;
    head = nullptr;
    tail = nullptr;
    for (int e: initial) {
        append(e);
}
}

};
int main() {
  LinkedList l;
  cout << ("Appends 1,2, 3 and 4, inserts 4 to index 1") << endl;
  l.append(1);
  l.append(2);
  l.append(3);
  l.append(4);
  l.insert(4, 1);
  l.print();
  cout << ("Removes at index 2, pops at index 1") << endl;
  l.remove(2);
  l.pop(1);
  l.print();
  cout << ("Testing pop()") << endl;
  l.pop();
  l.print();
  cout << ("Testing overload") << endl;
  LinkedList L({1,2,3,4,5});
  L.print();
  return 0;
}
