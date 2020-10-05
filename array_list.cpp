//#include <string>
#include <iostream>
#include <cassert>
//#include <cstdio>

class ArrayList {
    private: 
        double *x;
        int n = 1;
        int size = 0;
        int growth = 2;
        int capacity = n;
    public: ArrayList(){
        x = new double[n];
	    for (int i=0; i<n; i++){
	        x[i] = 0;
            //i *= 2;
		    //std::cout << x[i] << std::endl;
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
            size += 1;
        } else {
            resize();
        }
    };
    private:
    void resize(){
        capacity *= growth;
        double *tmp = new double[capacity];
        for (int i=0; i<size; i++) {
            tmp[i] = x[i];
        }
        delete[] x;
        x = tmp;
    }
    public:
    void print(){ //Hvordan får man den til å printe
        for (int i=0; i<n; i++){
		    std::cout << x[i] << std::endl;
        }
    };
};

bool is_prime(int N){
    ArrayList x();
    int i = 2;
    while(i <= N){
        int k=2;
        while(k <= i){
            if (k==i) { // Dette er sketchy kode og kan føre til bugs
		        //std::cout << "her" << std::endl;
                ArrayList a;
                a.append(i);
                a.print();
                //k++;
                break;
            }
            else if (i % k == 0){
		        //std::cout << "her**" << std::endl;
                break;
            }
            else {
                k++;
            }
        }
        i++;
    }
    return true;
};

bool test_is_prime(){
    is_prime(10);
    return true;
}

int main(){
    ArrayList a;
    //a.print();
    test_is_prime();
    return 0;
}