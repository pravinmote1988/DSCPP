#include <iostream>
#include <stack>

using namespace std;

// output 
// Identical

struct Node{
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

bool CheckIdenticalTrees(Node *node1,Node *node2)
{    
    if(node1 == nullptr || node2 == nullptr){
        return (node1 == node2);
    }

    return (node1->data == node2->data) && CheckIdenticalTrees(node1->left, node2->left)
            && CheckIdenticalTrees(node1->right, node2->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(5);

    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->left->left = new Node(5);

    auto a = CheckIdenticalTrees(root, root1);
    auto reply = (CheckIdenticalTrees(root, root1) == true) ? "Identical" : "Not Identical";
    cout << reply << endl;;

    return 0;
}