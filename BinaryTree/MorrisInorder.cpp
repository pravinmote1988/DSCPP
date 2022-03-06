#include <iostream>
#include <stack>

using namespace std;

// output 
// 4 2 5 1 6 3 7

struct Node{
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

void MorrisInorder(Node *root)
{
    Node *cur = root;
    while(cur != nullptr)
    {
        if(cur->left == nullptr)
        {
            cout << cur->data << " ";
            cur = cur->right;
        }
        else{
            Node *prev = cur->left;
            while(prev->right != nullptr && prev->right != cur)
                prev = prev->right;
            
            if(prev->right == nullptr)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else if(prev->right == cur)
            {
                prev->right = nullptr;
                cout << cur->data << " ";
                cur = cur->right;
            }
        }
    }
}

void MorrisPreOrder(Node *root)
{
    Node *cur = root;
    while(cur != nullptr)
    {
        if(cur->left == nullptr)
        {
            cout << cur->data << " ";
            cur = cur->right;
        }
        else{
            Node *prev = cur->left;
            while(prev->right != nullptr && prev->right != cur)
                prev = prev->right;
            
            if(prev->right == nullptr)
            {
                prev->right = cur;
                cout << cur->data << " ";
                cur = cur->left;
            }
            else if(prev->right == cur)
            {
                prev->right = nullptr;
                cur = cur->right;
            }
        }
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    MorrisInorder(root);
    cout << endl;
    MorrisPreOrder(root);
    cout << endl;

    return 0;
}