#include <iostream>
#include <stack>

using namespace std;

// output 
// 4 2 5 1 6 3 7

struct Node{
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

void printIterativeInorderOrder(Node *root)
{
    stack<Node*> st;
    Node *node = root;

    while(true) {

        if(node != nullptr) {
            st.push(node);
            node = node->left;
        }
        else {
            if(st.empty())
                break;
            
            node = st.top();
            st.pop();
            cout << node->data<< " ";

            node = node->right;
        }
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

    printIterativeInorderOrder(root);

    return 0;
}