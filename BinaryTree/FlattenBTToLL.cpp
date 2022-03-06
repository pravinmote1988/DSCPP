#include <iostream>
#include <stack>

using namespace std;

// output 
// 1 2 3 4 5 6 7 

struct Node{
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

class solution {
    
    Node *prev = nullptr;

    public:
    void flatten(Node *node)
    {
        if(node == nullptr) return;

        flatten(node->right);
        flatten(node->left);

        node->right = prev;
        node->left = nullptr;
        prev=node;
    }
};
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    solution s;
    s.flatten(root);
    while(root != nullptr)
        cout << root->data << " ", root= root->right;

    return 0;
}