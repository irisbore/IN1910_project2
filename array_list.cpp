//#include <string>
#include <iostream>
#include <cassert>
#include <vector>       
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
    void print(){ //Hvordan får man den til å printe
        for (int i=0; i<size; i++){
		    std::cout << x[i] << std::endl;
        }
    };
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

int main(){
    ArrayList a;
    a.print();
    test_is_prime();
    ArrayList primes({2, 3, 5, 8, 11});
    primes.print();
    return 0;
}