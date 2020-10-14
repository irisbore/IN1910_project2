//#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include  <stdexcept>

//#include <cstdio>

class ArrayList {
    private:
        int *x;
        int n = 1;
        int size = 0;
        int growth = 2;
        int capacity = n;
    public: ArrayList(){
        x = new int[capacity];
	    /*for (int i=0; i<n; i++){
	        x[i] = 0;
            //i *= 2;
		    //std::cout << x[i] << std::endl;
	    }*/
    }

    ArrayList(std::vector<int> vect){
        x = new int[capacity];
        for (int i: vect){
            append(i);
        }
    }

    public:
    int length() {
        return size;
    }
    ~ArrayList() {
        delete[] x;
    }
    public:
    void append(int n) {
        if (size < capacity) {
            x[size] = n;
        } else {
            resize();
            x[size] = n;
        }
        size += 1;
    };
    private:
    void resize(){
        capacity *= growth;
        int *tmp = new int[capacity];
        for (int i=0; i<size; i++) {
            tmp[i] = x[i];
        }
        delete[] x;
        x = tmp;
    }

    public:
    void print(){
        std::cout << "[";
        for (int i=0; i<size-1; i++){
		    std::cout << x[i];
            std::cout << ", ";
        }
        std::cout << x[size-1] << "]" << std::endl;
    }

    int& operator[](int i){
        if (i>=size){
            throw std::out_of_range("Index is out of range");
        }
        else{
            return x[i];
        }
    }

    void insert(int val, int index){ 
        if (index > size){
            throw std::out_of_range("Index is out of range");
        }
        else if (index == size){
            append(val);
        }
        else{
            append(x[size]);
            for (int i=size; i>index; i--){
                x[i] = x[i-1];
            }
            x[index] = val;
        }
    }

    void remove(int index){ // lag en for index==size
        if (index > size){
            throw std::out_of_range("Index is out of range");
        }
        else{
            size = size - 1; 
            for (int i=index; i<size; i++){
                x[i] = x[i+1]; 
            } 
        }
        if (capacity > 4*size){
            shrink_to_fit();
        }
    }

    int pop(int index){ //skal man repetere koden eller kun kalle på remove?
        int val = x[index];
        remove(index);
        return val;
    }

    int pop(){
        return pop(size-1);
    }

    void shrink_to_fit(){
        std::cout << "Original capacity:" << capacity << std::endl;
        if (capacity >= 2*size){
            capacity /= growth;
            int *tmp = new int[capacity];
            for (int i=0; i<size; i++) {
                tmp[i] = x[i];
            }
            delete[] x;
            x = tmp;
            std::cout << "New capacity:" << capacity << std::endl;
        }
        else{
            std::cout << "Current capacity is necessary to store the array" << std::endl;
        }
    }
};


bool is_prime(int n){
    if (n == 1) {
        return false;
    }

    for (int d=2; d<n; d++) {
        if (n % d == 0) {
            return false;
        }
    }
    return true;
}

void test_is_prime(){
    int n=1;
    ArrayList a;
    while(a.length() <10){
        if (is_prime(n)){
            a.append(n);
        }
        n++;
    }
    a.print();
}

void test_shrink_to_fit(){
    ArrayList primes({2, 3, 5, 8, 11});
    primes.print();
    primes.remove(1);
    primes.remove(1);
    primes.shrink_to_fit();
    primes.print();
    primes.remove(1);
    primes.remove(1);
    primes.shrink_to_fit();
    primes.print();
}

int main(){
    ArrayList a;
    //a.print();
    test_is_prime();
    ArrayList primes({2, 3, 5, 8, 11});
    //primes.insert(4, 2);
    //primes.print();
    //primes.remove(2);
    //primes.print();
    //test_shrink_to_fit();
    std::cout << primes.pop() << std::endl;
    primes.print();
    return 0;
}
