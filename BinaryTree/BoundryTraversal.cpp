#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

// Output 
// 1 2 4 5 6 7 3  
// 1 2 3 4 5 6 12 10 11 9 8 7 

struct Node{
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

void inorder(Node *node, vector<int> &vec){
    if(node== nullptr)
        return;
    
    inorder(node->left, vec);

    if(node->left == nullptr && node->right == nullptr)
        vec.push_back(node->data);  

    inorder(node->right, vec);
}

vector<int> boundryTraversal(Node *root)
{
    vector<int> boundry;
    if(root == nullptr)
        return boundry;  

    Node *node = root;
    // Step 1 - left Boundry excluding leaf
    while(!(node->left == nullptr && node->right == nullptr)) {

        while(node->left != nullptr) {
            boundry.push_back(node->data);
            node = node->left;
        }
        if(node->right != nullptr) {
            boundry.push_back(node->data);
            node = node->right;
        }        
    }

    //Step 2 - Add leaf nodes

    inorder(root, boundry);

    // step 3 - Add right boundry nodes(excluding leaf nodes) in reverse order
    stack<int> st;
    node = root->right;
    while(!(node->left == nullptr && node->right == nullptr)) {

        while(node->right != nullptr) {
            st.push(node->data);
            node = node->right;
        }
        if(node->left != nullptr) {
            st.push(node->data);
            node = node->left;
        }        
    }

    while(!st.empty()) {
        boundry.push_back(st.top());
        st.pop();
    }

    return boundry;
}

int main()
{
    // Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(12);
    root->left->left->right = new Node(4);
    root->left->left->right->left = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->left->left = new Node(10);
    root->right->right->left->right = new Node(11);

    auto boundry = boundryTraversal(root);

    for(auto val: boundry){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}