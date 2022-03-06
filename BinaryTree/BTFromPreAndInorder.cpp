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

Node *constructBT(vector<int> &preorder, int prestart, int preend,
                  vector<int> &inorder, int instart, int inend, map<int, int> inMap
                  )
{
    if(prestart > preend || instart > inend) return nullptr;

    Node *node = new Node(preorder[prestart]);
    int inroot = inMap[node->data];
    int numLeft = inroot - instart;

    node->left = constructBT( preorder, prestart+1, prestart+numLeft, 
                              inorder, instart, inroot-1, inMap);

    node->right = constructBT( preorder, prestart+numLeft+1, preend,
                              inorder, inroot+1, inend, inMap);  

    return node;  
}
Node* constructBT(vector<int> &preorder, vector<int> &inorder)
{    
    map<int, int> inMap;
    for(int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i; 
    
    Node *root = constructBT(preorder, 0, preorder.size()-1, 
                             inorder, 0, inorder.size()-1, inMap );

    return root;
}

void getInorder(Node* root)
{
    if(root == nullptr)
        return;

    getInorder(root->left);
    cout << root->data << " ";
    getInorder(root->right);
}

int main()
{
    vector<int> inorder = {9,3,15,20,7}; // output
    vector<int> preorder = {3,9,20,15,7};

    Node *root = constructBT(preorder, inorder);
    getInorder(root);
    cout << endl;
    return 0;
}