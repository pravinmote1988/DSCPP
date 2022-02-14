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
    if(root == nullptr) return;

    stack<Node*> st;

    Node *cur = root;

    while(cur != nullptr || !st.empty()) {
        if(cur != nullptr){
            st.push(cur);
            cur = cur->left;
        }
        else {
            
            Node *temp = st.top()->right;
            if(temp == nullptr) {
                
                temp = st.top();
                st.pop();

                cout << temp->data << " ";

                while(!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
            else{
                cur = temp;
            }
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

    printIterativePostorderOrder(root);

    return 0;
}