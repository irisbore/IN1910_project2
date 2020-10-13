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
      //head->next = tail;
      //tail->previous = head;
      size = 0;
      }

    int length() {
      return size;
  }

void print() {
    Node* current = head;
    cout << "[";
    while (current != nullptr) {
        cout << current->value;
        cout << ", ";
        current = current->next;
    cout << current->value << "]" << endl;
}
}

//Destructor
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
}

int& operator[] (int index) {
  if (index < 0 or index >= size) {
        throw range_error("IndexError: Index out of range");
      }

  Node* current = head->next;

  for (int i=0; i<index; i++) {
    current = current->next;
    }
    return current->value;
}

void append(int val){
  Node* a = new Node(val);
  tail->next = a;
  tail = a;
  size++;
}

void insert(int val, int index){
  Node* current = head;
  for(int i = 0; i<index;){
    current = current->next;
  }

  Node* a = current->next;
  current->next = new Node(val);
  current->next->next = a;
  size++;
}

void remove(int stop){
  Node* current = current;
  for(int i=0; i<stop; i++)
{
  current = current->next;
}
  delete[] current;
}


int pop(int val) {
  for(int i=0; i<val; i++)
  Node* current = current;
{
  current = current->next;
}
  return current;
  delete[] current;
}

int pop(){
  Node* a = tail->previous;
  return a;
  delete a;
}

//Overload constructor
LinkedList(vector<int> initial) {
    int size = 0;
    int capacity = 10000;
    data = new int[capacity];

    for (int e: initial) {
        append(e);
    }
}
};

int main() {
  LinkedList l;
  l.append(4);
  l.append(3);
  l.append(2);
  l.insert(3, 1);
  l.print();
  l.remove(2);
  return 0;
}

def 
