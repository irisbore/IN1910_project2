#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

//Struct
struct Node {
    int value;
    Node* previous;
    Node* next;


    Node(int val) {
    next = nullptr;
    previous = nullptr;
    value = val;
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
    cout << current->value << "]" << endl;
}
}

//Destructor
~LinkedList() {
    Node* current;
    Node* next;

    current = head;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

int& operator[] (int index) {
  if (index < 0 or index >= size) {
        throw range_error("IndexError: Index out of range");
      }

  Node* current = head;

  for (int i=0; i<index; i++) {
    current = current->next;
    }
    int val = current->value;
    return val;
}

void append(int val){
  Node* a = new Node(val);
  tail->next = a;
  tail = a;
  size++;
}
/*
void insert(int val, int index){
  Node* current = head;
  for(int i = 0; i<index; i++){
    current = current->next;
  }

  Node* a = current->next;
  current->next = new Node(val);
  current->next->next = a;
  size++;
}

void remove(int stop){
  Node* current = head;
  for(int i=0; i<stop; i++)
{
  current = current->next;
}
  delete[] current;
  size--;
}


int pop(int index) {
  Node* current = head;
  for(int i=0; i<index; i++)
{
  current = current->next;
}
  remove(index);
  int pop_value = current->value;
  return pop_value;

}

int pop(){
  pop(size-1);
}
*/

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
  l.length();
  //l.print();
  /*
  l.append(2);
  l.append(3);
  l.append(3);
  l.insert(3, 1);
  l.print();
  l.remove(3);
  l.pop(2);
  l.print();*/

  //TEST OVERLOAD
  LinkedList L({1,2,3});
  return 0;
}
