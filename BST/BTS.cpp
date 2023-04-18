using namespace std;
#include <iostream>

template<class T>


class BTS {

    struct Node {
        T data;
        Node* left;
        Node* right;

    };

    Node* root;

    Node* assign(T x, Node* a) {
        if (a == NULL) {
            a = new Node();
            a->data = x;
            a->left = NULL;
            a->right = NULL;

        }
        else if (x < a->data)
            a->left = assign(x, a->left);

        else if (x > a->data)
            a->right = assign(x, a->right);

        return a;

    }

    void inorder(Node* a) {

        if (a != NULL) {


            inorder(a->left);  //sprawdzamy lewa str, lecimy do konca
            cout << a->data << "  "; //wyswietlamy lewa
            inorder(a->right);         //jak nie ma lewej przypisz prawa, potem wyswietl

        }

    };

    void preorder(Node* a) {

        if (a != NULL) {

            cout << a->data << "  ";
            preorder(a->left);  //sprawdzamy lewa str, lecimy do konca
            preorder(a->right);         //jak nie ma lewej przypisz prawa, potem wyswietl

        }

    };
    void clearBST(Node* a)
    {
        if (a != NULL) {
            clearBST(a->left);
            clearBST(a->right);

            delete a;
        }


    }

public:
    BTS();
    ~BTS();
    void assign(T x) {
        root = assign(x, root);
    }
    void show() {
        inorder(root);
        cout << endl;
    }
    void show2() {
        preorder(root);
        cout << endl;
    }
    void clearBST() {
        clearBST(root);
        cout << endl;
    }


};

template<class T>
BTS<T>::BTS() {

    root = NULL;

}
template<class T>
BTS<T>::~BTS() {
    delete root;
}



int main()
{
    BTS<int>* dll = new BTS<int>();
    const int MAX_ORDER = 4;
    const int n = pow(10, MAX_ORDER);
    srand(time(0));



   /* for (int i = 0; i < n; i++)
    {

        clock_t start2 = clock();

        dll->assign(rand() % 10000);

    }
   */

    

     dll->assign(10);
     dll->assign(15);
     dll->assign(12);
     dll->assign(5);

     dll->assign(30);
     dll->assign(25);
     dll->assign(35);
     dll->assign(7);

     dll->show2();  //preorder
     dll->show();  //inorder


     delete dll;
     
}

