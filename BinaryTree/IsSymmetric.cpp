#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

// Output 
// 

struct Node {
    int data;
    Node* left;
    Node* right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

bool isSymmetrichelp(Node *leftNode, Node *rightNode);
bool isSymmetric(Node* node)
{    
    return node == nullptr || isSymmetrichelp(node->left, node->right);
}

bool isSymmetrichelp(Node *leftNode, Node *rightNode)
{
    if(leftNode == nullptr || rightNode == nullptr)
        return leftNode == rightNode;

    if(leftNode->data != rightNode->data)
        return false;

    return isSymmetrichelp(leftNode->left, rightNode->right) && 
            isSymmetrichelp(leftNode->right, rightNode->left);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(4);

    string ans = isSymmetric(root) ? "Symmetric" : "Not Symmetric";
    cout << ans;
    cout << endl;
    return 0;
}