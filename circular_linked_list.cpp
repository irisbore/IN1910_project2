#include <iostream>
#include <cassert>
#include <vector>
#include  <stdexcept>

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
            size ++; //          Jeg har size++ i både CirkLinkedList(n) og append. HVORFOR??
            i++;
        }/*
        head = nullptr;
        tail = nullptr;
        int i = 1;

        if (head == nullptr) {
            head = new Node(i);
            size ++;
        }
        else{
            Node* current;
            current = head;
            while (i<=n){
                append(i);
                //current->next = new Node(i);
                //current = current->next;
                size ++;
                i++;
            }
        }*/
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
        tail=new_node;
        new_node->next = head;
    }/*
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
    }*/
    
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
    void remove(int index){
        Node* previous = head;
        Node* current = head;
        //Node* next;
        if (current == nullptr){
            std::cout << "Empty list" << std::endl;
            return;
        }
        for(int i=0; i<index; i++){
            current = current->next;
            //std::cout << current->value << std::endl;
        }
        std::cout << current->value << std::endl;
        previous->next = current->next;
        delete current;
        //next = current->next;
        size--;
    }

    std::vector<int> josephus_sequence(int k){
        int i = 1;
        std::vector<int> x{};
        Node* current = head;
        while(i<size){
            if(current==nullptr){
                break;
            }
            for (int j=0; j<k; j++){
                current = current->next;
            }
            //std::cout << current->value << std::endl;
            remove(i);
            size--;
            x.push_back(current->value);
            //i ++;
        }
        return x;
    }
};

int last_man_standing(int n, int k){
    CircLinkedList a{n};
    std::vector<int> x = a.josephus_sequence(k);
    //std::cout << x[0] << std::endl;
    return x[n];
};

int main(){
    CircLinkedList clist;
    clist.append(0);
    clist.append(2);
    clist.append(4);
    clist.remove(1);
    clist.print();
    last_man_standing(6, 3);
    //std::cout << last_man_standing(6, 3) << std::endl;
    return 0;
}