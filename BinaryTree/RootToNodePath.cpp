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

bool rootToNodePath(Node* root, int value, vector<int> &ans)
{    
    if(root == nullptr)
        return false;

    ans.push_back(root->data);

    if(root->data == value)
        return true;

    if(rootToNodePath(root->left, value, ans) ||rootToNodePath(root->right,value, ans) )
        return true;

    ans.pop_back();
    return false;
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

    vector<int> ans;
    rootToNodePath(root,  7, ans);
    for(int node: ans)
    {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}