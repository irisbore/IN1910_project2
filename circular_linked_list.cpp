#include <iostream>
#include <cassert>
#include <vector>
#include  <stdexcept>
#include <cstddef>

struct Node {
    int value;
    Node* next;
    Node* previous;

    Node(int n) {
        value = n;
        next = nullptr;
        previous = nullptr;
    }
    Node(int n, Node* p) {
        value = n;
        next = p;
    }
};

class CircLinkedList{
    private:
    Node* head;
    Node* tail;
    int size = 0;

    public:
    CircLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    CircLinkedList(int n){
        head = nullptr;
        tail = nullptr;
        int i = 1;
        while (i<=n){
            append(i);
            i++;
        }
    }

    void append(int val) {
        Node* new_node = new Node(val);
        size ++;
        if (head==nullptr){
            head = new_node;
            new_node->next = new_node;
            tail = new_node;
        }
        tail->next = new_node;
        new_node->next = head;
        tail=new_node;
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
        std::cout << current->value << ", ...]" << std::endl;
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
    std::vector<int> josephus_sequence(int k){
        std::vector<int> x{};
        Node* previous = tail;
        Node* current = head;
        while(current->next !=current){
            for (int j=1; j<k; j++){
                previous = current;
                current = current->next;
            }
            x.push_back(current->value);
            previous->next = current->next;
            delete current;
            current = previous->next;
            size--;
        }
        x.push_back(current->value);
        delete current;
        return x;
    }
};

int last_man_standing(int n, int k){
    CircLinkedList a{n};
    std::vector<int> x = a.josephus_sequence(k);
    return x[n-1];
};

int main(){
    CircLinkedList clist;
    clist.append(0);
    clist.append(2);
    clist.append(3);
    clist.append(4);
    clist.append(5);
    clist.print();
    std::cout << last_man_standing(6, 3) << std::endl;
    return 0;
}