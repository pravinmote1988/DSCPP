#include <iostream>
#include <stack>

using namespace std;

// output 
// 4 5 2 6 7 3 1

struct Node{
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

void printIterativePostorderOrder(Node *root)
{
    if(root!= nullptr) return ;

    stack<Node*> st1, st2; 
    st1.push(root);

    while(!st1.empty()) {

        Node *node = st1.top();
        st1.pop();

        st2.push(node);

        if(node->left != nullptr) 
            st1.push(node->left);
        
        if(node->right != nullptr)
            st1.push(node->right);
    }

    while(!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
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

    printIterativePostorderOrder(root);

    return 0;
}