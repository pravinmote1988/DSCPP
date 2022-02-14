#include <iostream>
#include <stack>

using namespace std;

// output 
// -1 i.e. Not Balanced

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
    if(lh == -1)
        return -1;
    int rh = maxDepth(node->right);
    if(rh == -1)
        return -1;
    
    if(abs(lh - rh) > 1)
        return -1;

    return max(lh , rh ) +1;  
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(5);

    cout << maxDepth(root) << endl;;

    return 0;
}