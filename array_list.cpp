#include <string>
#include <iostream>
#include <cassert>
//#include <cstdio>

class ArrayList {
    private: 
        double *x;
        int n = 1;
        int size = 0;
        int capacity = n;
    public: ArrayList(){
        x = new double[n];
	    for (int i=0; i<n; i++){
	        x[i] = 0;
            i *= 2;
		    std::cout << x[i] << std::endl;
	    }
    }
    public:
    int length() {
        return 0;
    }
    ~ArrayList() {
        delete[] x;
    }
    private:
    void append(int n) {
        if (size < capacity) {
            x[size] = n;
            size += 1;
        } else {
            throw std::range_error("Capacity full");
        }
    };
    private:
    void resize(){
        capacity *= 2;
        double *tmp = new double[capacity];
        for (int i=0; i<size; i++) {
            tmp[i] = x[i];
        }
        delete[] x;
        x = tmp;
    }
    public:
    void print(){
        for (int i=0; i<n; i++){
		    std::cout << x[i] << std::endl;
        }
    };
};

int main(){
    ArrayList a;
}