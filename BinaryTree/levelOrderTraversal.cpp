#include <iostream>
#include <queue>

using namespace std;

// Output 
// 1 2 3 4 5 6 7 

struct Node{
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

void printLevelOrder(Node *root)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node *node = q.front();
        q.pop();

        cout << node->data << " ";

        if(node->left != nullptr)
            q.push(node->left);
        
        if(node->left != nullptr)
            q.push(node->right);
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

    printLevelOrder(root);

    return 0;
}