#include<iostream>
using namespace std;

typedef struct Node* Bstreeptr;

class BST {

    struct Node
 {
        int data;
        Node* left;
        Node* right;
    };

    Node* root;

    Node* makeEmpty(Node* t) {
        if (t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    Node* insert(int x, Node* t)
    {
        if (t == NULL)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if (x < t->data)
        {
            t->left = insert(x, t->left);
        }
        else if (x > t->data)
        {
            t->right = insert(x, t->right);
        }
        else if(x == t->data)
        {
            cout << "\nSorry! Duplicates not allowed\n";
        }
        return t;
    }

    Node* findMin(Node* t)
    {
        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    Node* findMax(Node* t) {
        if (t == NULL)
            return NULL;
        else if (t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    Node* remove(int x, Node* t) {
        Node* temp;
        if (t == NULL)
            return NULL;
        else if (x < t->data)
            t->left = remove(x, t->left);
        else if (x > t->data)
            t->right = remove(x, t->right);
        else if (t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(Node* t) {
        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    Node* find(Node* t, int x) {
        if (t == NULL)
        {
            cout << "\nNot Found\n";
            return NULL;
        }
        else if (x < t->data)
            return find(t->left, x);
        else if (x > t->data)
            return find(t->right, x);
        else
            cout << "\nFound\n";
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        root = makeEmpty(root);
    }

    void insert(int x) {
        root = insert(x, root);
    }

    void remove(int x) {
        root = remove(x, root);
    }

    void display() {
        inorder(root);
        cout << endl;
    }

    void search(int x) {
        root = find(root, x);
    }
};

int main() {
    BST objBT;
    int data;
    short int choice = 0;

    while (choice != 4)
    {
        cout << "\n**********************************\n";
        cout << "\t1. Insert Data";
        cout << "\n\t2. Search Data";
        cout << "\n\t3. Print Data";
        cout << "\n**********************************\n";

        cout << "\n\tChoice >>  ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\nEnter data to be inserted\n";
            cout << "Data >>\t";
            cin >> data;
            objBT.insert(data);
        }
        else if (choice == 2)
        {
            cout << "\nEnter data to be searched\n";
            cout << "Data >>\t";
            cin >> data;
            objBT.search(data);
        }
        else if (choice == 3)
        {
            cout << "\nPrinting Binary Search Tree\n";
            objBT.display();
        }
        else if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
        {
            system("cls");
            cout << "\nInvalid key entered\n";
            cout << "\nPlease continue again\n";
        }
    }
}