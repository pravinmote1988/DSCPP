#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

int findLeftHeight(Node *node)
{
    int height = 1;
    while(node != nullptr)
    {
        height++;
        node = node->left;
    }
    return height;
}

int findRightHeight(Node *node)
{
    int height = 1;
    while(node != nullptr)
    {
        height++;
        node = node->right;
    }
    return height;
}

int nodes(Node *root)
{    
    if(root == nullptr)
        return 0;

    int lh = findLeftHeight(root->left);
    int rh = findRightHeight(root->right);

    if(lh == rh) return (1 << rh) -1;

    return 1 + nodes(root->left) + nodes(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    //root->right->right = new Node(7);

    cout << nodes(root);
    
    cout << endl;
    return 0;
}