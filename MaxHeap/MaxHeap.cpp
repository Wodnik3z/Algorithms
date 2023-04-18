#include <iostream>
#include <time.h>
#include <string>
using namespace std;

template <class T>
class MaxHeap {
    T* array;

public:
    int capacity = 2;
    int size = 1;

    MaxHeap();

    void insert(T value) {
        if (size > capacity || size == capacity) {
            capacity = capacity * 2;
            T* Nowyarray = new T[capacity];
            for (int i = 0; i < size; i++) {
                Nowyarray[i] = array[i];
            }
            delete[] array;
            array = Nowyarray;
        }
        array[size++] = value;

        T child = size - 1;
        T parent = (size - 1) / 2;
        while (array[parent] < array[child] && parent >0) {
            T tmp = array[parent];
            array[parent] = array[child];
            array[child] = tmp;
            child = parent;
            parent = child / 2;
        }
    }

    void print() {
        for (int i = 1; i < size; i++) {
            cout << array[i] << "\n";
        }
    }

    void getRoot() {
        cout << "Root: " << array[1];
    }

    void clear() {
        size = 0;
        delete[] array;
        array = new T[size];
        array[0] = NULL;
    }

    std::string to_string() {
        std::string str = " ";
        for (int i = 1; i < size; i++) {
            str += std::to_string(array[i]) + "\n";
        }
        return str;
    }

    void extractMax() {
        // TODO
    }
};

template <class T>
MaxHeap<T>::MaxHeap() {
    array = new T[capacity];
}

int main() {
    MaxHeap<int>* daa = new MaxHeap<int>();
    const int Maxx = 2;
    const int n = pow(10, Maxx);
    
    srand(time(0));

    for (int i = 0; i < n; i++) {
        
        daa->insert(rand() % 1000);

    }
    

    std::string str = daa->to_string();
    cout << str << std::endl;

    daa->getRoot();
    daa->clear();

    return 0;
}
