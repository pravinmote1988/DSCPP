#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// output 
// Pre 1 2 4 5 3 6 7 
// In 4 2 5 1 6 3 7
// Post 4 5 2 6 7 3 1

struct Node{
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

void printIterativePreorderOrder(Node *root)
{
    stack<pair<Node*,int>> st;
    st.push({root, 1});

    vector<Node*> pre, in, post;

    while(!st.empty()) {

        auto it = st.top();
        st.pop();

        if(it.second == 1) {
            pre.push_back(it.first);
            it.second++;
            st.push(it); 

            if(it.first->left != nullptr)
                st.push({it.first->left, 1});
        }
        else if( it.second == 2) {
            in.push_back(it.first);
            it.second++;
            st.push(it);

            if(it.first->right != nullptr)
                st.push({it.first->right, 1});
        }
        else if(it.second == 3) {
            post.push_back(it.first);
        }
    }
    
    cout << "Pre : - ";
    for(Node *node:pre) {
        cout << node->data << " ";
    }

    cout << "In : - ";
    for(Node *node:in) {
        cout << node->data << " ";
    }

    cout << "Post : - ";
    for(Node *node:post) {
        cout << node->data << " ";
    }
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

    printIterativePreorderOrder(root);

    return 0;
}