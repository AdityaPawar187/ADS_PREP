#include <iostream>
#include <stack>

using namespace std;

struct node
{
    char data;
    node *left;
    node *right;

    node(char val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class expr
{

public:
    bool isoperator(char c)
    {
        if (c == '+' || c == '-' || c == '/' || c == '*')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    node *createexpr(string &ch)
    {
        stack<node *> stck;

        for (int i = 0; i < ch.size() ; i++)
        {
            char currchar = ch[i];
            if (isalnum(currchar))
            {
                stck.push(new node(currchar));
            }
            else if (isoperator(currchar))
            {
                node *operand1 = stck.top();
                stck.pop();
                node *operand2 = stck.top();
                stck.pop();

                node *newnode = new node(currchar);

                newnode->left = operand2;
                newnode->right = operand1;

                stck.push(newnode);
            }
        }
        return stck.top();
    }

    void inorder(node *temp)
    {
        if (temp != NULL)
        {
            inorder(temp->left);
            cout<<" "<<temp->data;
            inorder(temp->right);
        }
    }
};

int main()
{
    expr e;

    cout << "Enter the prefix expression";
    string str;
    cin >> str;

    node *root = e.createexpr(str);

    e.inorder(root);
}
