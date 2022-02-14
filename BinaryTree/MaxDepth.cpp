#include <iostream>
#include <stack>

using namespace std;

// output 
// 3

struct Node{
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

int maxDepth(Node *node)
{    
    if(node == nullptr)
        return 0;

    int lh = maxDepth(node->left);
    int rh = maxDepth(node->right);
    return 1 + max(lh , rh );    
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
    root->right->left->right = new Node(8);

    cout << maxDepth(root) << endl;;

    return 0;
}