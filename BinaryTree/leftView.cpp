#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>

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

void leftView(Node* node, int level, vector<int> &vec)
{    
    if(node == nullptr)
        return;

    if(level == vec.size())
        vec.push_back(node->data);

    if(node->left != nullptr) 
        leftView(node->left, level+1, vec);

    if(node->right != nullptr) 
        leftView(node->right, level+1, vec);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Node *root = new Node(1);
    // root->left = new Node(2);
    // root->left->left = new Node(3);
    // root->left->right = new Node(12);
    // root->left->left->right = new Node(4);
    // root->left->left->right->left = new Node(5);
    // root->left->left->right->right = new Node(6);
    // root->right = new Node(7);
    // root->right->right = new Node(8);
    // root->right->right->left = new Node(9);
    // root->right->right->left->left = new Node(10);
    // root->right->right->left->right = new Node(11);

    vector<int> ans;
    leftView(root, 0, ans);

    for (auto val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}