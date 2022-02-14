#include <iostream>
#include <stack>

using namespace std;

// output 
// 1 2 4 5 3 6 7 

struct Node{
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

void printIterativePreorderOrder(Node *root)
{
    stack<Node*> st;
    st.push(root);

    while(!st.empty()) {

        Node *node = st.top();
        st.pop();

        cout << node->data << " ";

        if(node->right != nullptr)
            st.push(node->right);

        if(node->left != nullptr)
            st.push(node->left);
    }
    cout << endl;
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