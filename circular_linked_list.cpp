#include <iostream>
#include <cassert>
#include <vector>
#include  <stdexcept>

struct Node {
    int value;
    Node* next;

    Node(int n) {
        value = n;
        next = nullptr;
    }
    Node(int n, Node* p) {
        value = n;
        next = p;
    }
};

class  CircLinkedList{
    private:
    Node* head;
    Node* tail;
    int size = 0;

    public:
    CircLinkedList() {
        head = nullptr;
    }
/*
    CircLinkedList(int n){
        int i = 1;
        if (head == nullptr) {
            head = new Node(i);
            size ++;
        }
        Node* current;
        current = head;
        while (i<=n){
            current->next = new Node(i);
            current = current->next;
            size ++;
        }
    }
*/
    void append(int val) {
        if (head == nullptr) {
            head = new Node(val, head);
            size ++;
            return;
        }        
        // Iterate to end of list
        Node* current;
        current = head;
        while (current->next != head) {
            current = current->next;
            std::cout << current->value << std::endl;
        }
    
        // Link new node to end of list
        current->next = new Node(val, head);
        //current->next->next = head;
        size ++;
    }
    int& operator[](int index){
        if (index < 0 || head==nullptr) {
            throw std::out_of_range("IndexError: Index out of range");
        }
        Node* current = head;
        for (int i=0; i<index; i++) {
            current = current->next;
        }
        return current->value;
    }
    void print() {
        Node* current = head;
        std::cout << "[";
        while (current->next != head) {
            std::cout << current->value;
            std::cout << ", ";
            current = current->next;
        }
        std::cout << current->value << "]" << std::endl;
    }
    ~CircLinkedList() {
        Node* current;
        Node* next;
    
        current = head;
    
        while (current != head) {
            next = current->next;
            delete current;
            current = next;
        }
    }
/*
    std::vector<int> josephus_sequence(int k){
        int i = 1;
        int *x;
        x = new int[size];
        Node* current;
        while(i<size){
            for (int j=1; j<=k; j++){
                current = current->next;
            }
            x[i] = current->value;
            i ++;
        }
        delete[] x;
        return x;
    }
*/
};

int main(){
    CircLinkedList clist;
    //clist.append(0);
    //clist.append(2);
    clist.append(4);
    clist.print();
    return 0;
}