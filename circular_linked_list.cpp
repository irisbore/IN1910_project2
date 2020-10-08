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
    int size = 0;

    public:
    CircLinkedList() {
        head = nullptr;
    }

    void append(int val) {
        if (head == nullptr) {
            head = new Node(val);
            size ++;
            return;
        }        
        // Iterate to end of list
        Node* current;
        current = head;
        while (current->next != head) {
            current = current->next;
        }
    
        // Link new node to end of list
        current->next = new Node(val);
        (current->next)->next = head;
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
};

int main(){
    return 0;
}