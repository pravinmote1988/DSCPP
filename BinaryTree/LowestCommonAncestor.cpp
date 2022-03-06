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

Node *lowestCommonAncestor(Node* root, Node * p, Node *q)
{    
    if(root == nullptr || root == p || root == q)
        return root;

    Node *left = lowestCommonAncestor(root->left, p, q);
    Node *right = lowestCommonAncestor(root->right, p, q);

    if(left == nullptr)
        return right;
    else if(right == nullptr)
        return left;
    else    
        return root;
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

    Node *ans = lowestCommonAncestor(root, root->right->left, root->right->right );
    if(ans != nullptr)
        cout << ans->data;
    cout << endl;
    return 0;
}