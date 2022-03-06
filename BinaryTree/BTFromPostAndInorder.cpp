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

Node *constructBT(vector<int> &postorder, int poststart, int postend,
                  vector<int> &inorder, int instart, int inend, map<int, int> inMap
                  )
{
    if(poststart > postend || instart > inend) return nullptr;

    Node *node = new Node(postorder[postend]);
    int inroot = inMap[node->data];
    int numLeft = inroot - instart;

    node->left = constructBT( postorder, poststart, poststart+numLeft-1, 
                              inorder, instart, inroot-1, inMap);

    node->right = constructBT( postorder, poststart+numLeft, postend-1,
                              inorder, inroot+1, inend, inMap);  

    return node;  
}
Node* constructBT(vector<int> &postorder, vector<int> &inorder)
{    
    map<int, int> inMap;
    for(int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i; 
    
    Node *root = constructBT(postorder, 0, postorder.size()-1, 
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
    vector<int> inorder = {40,20,50,10,60,30}; // output
    vector<int> postorder = {40,50,20,60,30,10};

    Node *root = constructBT(postorder, inorder);
    getInorder(root);
    cout << endl;
    return 0;
}