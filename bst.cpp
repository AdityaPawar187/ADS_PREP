#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
    node(int data1)
    {
        data = data1;
        right = NULL;
        left = NULL;
    }
};

class bst
{

public:
    node *root;
    bst()
    {
        root = NULL;
    }

    void insert1(int key)
    {
        root = insert2(root, key);
    }

    node *insert2(node *root1, int key)
    {
        if (root1 == NULL)
        {
            return new node(key);
        }

        if (root1->data < key)
        {
            root1->right = insert2(root1->right, key);
        }

        if (key < root1->data)
        {
            root1->left = insert2(root1->left, key);
        }

        return root1;
    }

    void inorder1()
    {
        cout<<"Inorder = ";
        inorder2(root);
    }

    void inorder2(node *temp)
    {
        if (temp != NULL)
        {
            inorder2(temp->left);
            cout << temp->data << " ";
            inorder2(temp->right);
        }
    }

    void max1()
    {
        node *temp;
        temp = max2(root);
        cout <<endl <<"Max:" <<temp->data;
    }

    node *max2(node *temp)
    {
        if (temp == NULL)
        {
            return NULL; // Handle empty tree case
        }
        while (temp->right != NULL)
        {
            temp = temp->right; // Keep going right
        }
        return temp; // Rightmost node is the maximum
    }
};

int main()
{
    bst b;
    int nos;
    cout << "Enter the number of elements";
    cin >> nos;

    for (int i = 0; i < nos; i++)
    {
        int te = 0;
        cin >> te;
        b.insert1(te);
    }

    b.inorder1();
    b.max1();
}
