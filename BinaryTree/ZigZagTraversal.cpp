#include <iostream>
#include <queue>

using namespace std;

// Output 
// 1 
// 2 3 
// 7 6 5 4 

struct Node{
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

vector<vector<int>> zigZagOrder(Node *root)
{
    vector<vector<int>> zigZag;
    if(root == nullptr)
        return zigZag;  
    
    queue<Node*> q;
    q.push(root);

    bool leftToRight = false;
    
    while(!q.empty()) {
        int size = q.size();
        vector<int> levelVec(size);

        for(int i =0; i < size; i++) {
            Node *node = q.front();
            q.pop();

            int index = (leftToRight) ? i : (size-1-i);

            levelVec[index]=node->data;

            if(node->left != nullptr)
                q.push(node->left);
            
            if(node->left != nullptr)
                q.push(node->right);
        }
        leftToRight = !leftToRight;
        zigZag.push_back(levelVec);
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

    auto zigZagVec = zigZagOrder(root);

    for(auto vec: zigZagVec){
        for(auto val : vec){
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}