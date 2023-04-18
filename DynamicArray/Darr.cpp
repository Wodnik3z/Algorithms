
#include <iostream>
#include <time.h>
#include <string>
using namespace std;



template <class T>
class DynamicArray {

    int  size = 0;
    int capacity = 1; //capty start
    T* array;



public:
    DynamicArray();
    ~DynamicArray();
    void assignTail(T n);
    int recieveIndex(T w);
    void swapIndex(T k, T j);
    void show();
    void clear();
    void bubble();

    int elements = 0;

};

template <class T>
DynamicArray<T>::DynamicArray()
{

    array = new T[capacity];

}


template <class T>
DynamicArray<T>::~DynamicArray()
{
    delete[] array;
}




template <class T>

void DynamicArray<T>::assignTail(T n)
{
    if (size == capacity) {
        int cap = capacity * 2;
        T* temp = new T[cap];

        for (int i = 0; i < size; i++) {
            temp[i] = array[i];
        }
        delete[] array;
        array = NULL;
        array = temp;
        capacity = cap;
    }

    array[size] = n;
    size++;


    DynamicArray::elements += 1;

}





template <class T>

int DynamicArray<T>::recieveIndex(T w)
{
    if (w > capacity) {
        cout << "nie ma takiego indexu\n";
    }

    return array[w];

}
template <class T>
void DynamicArray<T>::swapIndex(T k, T j)  //k miejsce  w tablicy, j to co chce wstawic

{
    if (k > capacity) {
        cout << "nie ma takiego indexu\n";
    }
    array[k] = j;
}

template <class T>
void DynamicArray<T>::bubble()
{

    for (int i = 0; i < DynamicArray::elements - 1; i++)
        for (int j = 0; j < DynamicArray::elements - i; j++)
            if (array[j] > array[j + 1])
            {
                int val1;
                int val2;
                val1 = array[j];
                val2 = array[j + 1];
                array[j + 1] = val1;
                array[j] = val2;


            }


    cout << "posortowano" << endl;


}

template <class T>

void DynamicArray<T>::show()
{
    if (size == 0)
    {
        cout << "Tablica jest pusta" << endl;

    }

    for (int i = 0; i < DynamicArray::elements; i++)
    {
        cout << array[i] << "  ";


    }

    cout << endl << "Rozmiar tablicy " << size << endl;


}

template <class T>
void DynamicArray<T>::clear() {

    size = 0;
    delete[] array;
    array = new T[size];
    array[0] = NULL;

}




int main()
{
    DynamicArray<int>* daa = new DynamicArray<int>();
    const int MAX_ORDER = 7;
    const int n = pow(10, MAX_ORDER);
    srand(time(0));
    
    int cc;


    daa->assignTail(69);
    daa->assignTail(51);
    daa->assignTail(33);
    daa->assignTail(60);
    daa->assignTail(1);
    daa->assignTail(1);

    daa->show();

    DynamicArray<char>* daa2 = new DynamicArray<char>();
    daa2->assignTail('a');
    daa2->assignTail('r');

    daa2->show();




    cout << "index 0\n";
    cout << "otrzymany index: " << daa->recieveIndex(0) << endl;
    
    daa->swapIndex(0, 1337);
    cout << "zeswapowany index\n";
    cout << daa->recieveIndex(0) << endl;


    //daa->bubble();

    delete daa;
    delete daa2;

   
   


}

