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

int maxPathSum(Node *node, int &sum)
{    
    if(node == nullptr)
        return 0;

    int lh = maxPathSum(node->left, sum);
    int rh = maxPathSum(node->right, sum); 
    
    sum = max(sum, lh +rh + node->data );
    return node->data + max(lh, rh);

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

    int sum =0;
    maxPathSum(root, sum);
    cout << sum << endl;;

    return 0;
}