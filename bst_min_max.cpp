#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class bst
{
public:
    node *root;

    void insert1(int key)
    {
        root = insert2(root, key);
    }

    node *insert2(node *root1, int key)
    {
        if (root1 == nullptr)
        {
            return new node(key);
        }

        if (key > root1->data)
        {
            root1->right = insert2(root1->right, key);
        }

        if (key < root1->data)
        {
            root1->left = insert2(root1->left, key);
        }

        return root1;
    }

    void inorder(node *temp)
    {
        if (temp != nullptr)
        {
            inorder(temp->left);
            cout << " " << temp->data;
            inorder(temp->right);
        }
    }

    void preorder(node *temp)
    {
        if (temp != nullptr)
        {
            cout << " " << temp->data;
            preorder(temp->left);
            preorder(temp->right);
        }
        cout << endl;
    }

    void postorder(node *temp)
    {
        if (temp != nullptr)
        {
            postorder(temp->left);
            postorder(temp->right);
            cout << " " << temp->data;
        }
        cout << endl;
    }

    int max(node *temp)
    {
        while (temp->right!=nullptr)
        {
            temp = temp->right;
        }
        return temp->data;
    }

    int min(node *temp)
    {
        while (temp->left!=nullptr)
        {
            temp = temp->left;
        }
        return temp->data;
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

    b.inorder(b.root);
    cout<<"\nMax: " <<b.max(b.root)<<endl;
    cout<<"Min = "<<b.min(b.root);
}