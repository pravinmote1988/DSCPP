#include <iostream>
#include <stack>

using namespace std;

// output 
// 4

struct Node{
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

int diameter(Node *node, int &dia)
{    
    if(node == nullptr)
        return 0;

    int lh = diameter(node->left, dia);
    int rh = diameter(node->right, dia);
    
    dia = max(dia, lh+rh);

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

    int dia =0;
    diameter(root, dia);
    cout << dia << endl;;

    return 0;
}