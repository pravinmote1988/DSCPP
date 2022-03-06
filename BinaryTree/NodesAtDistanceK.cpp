#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
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


void MarkParent(Node *root, unordered_map<Node*, Node*> &parent)
{   
    queue<Node*> que;
    que.push(root);

    while(!que.empty())
    {
        Node *node = que.front();
        que.pop();
        if(node->left != nullptr) {
            parent[node->left] = node;
            que.push(node->left);
        }
        if(node->right != nullptr) {
            parent[node->right] = node;
            que.push(node->right);
        }
    }
}

vector<Node*> nodesAtDistance(Node *root, Node *target, int distance)
{    
    unordered_map<Node*, Node*> parents;
    MarkParent(root, parents);

    unordered_map<Node*, bool> visited;
    queue<Node*> que;
    que.push(target);
    int count = 0;
    while(!que.empty())
    {
        if(count++ == distance)
            break;

        int size = que.size();

        for(int i = 0; i < size; i++) {
            Node *node = que.front();
            que.pop();
            visited[node] = true;

            if(node->left != nullptr && !visited[node->left]){
                que.push(node->left);
                visited[node->left] = true;
            }

            if(node->right != nullptr&& !visited[node->right]){
                que.push(node->right);
                visited[node->right] = true;
            }

            if(parents[node] != nullptr && !visited[parents[node]]){
                que.push(parents[node]);
                visited[parents[node]] = true;
            }
        }
    }

    vector<Node*> ans;
    while(!que.empty()){
        ans.push_back(que.front());
        que.pop();
    }

    return ans;
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

    vector<Node*> ans = nodesAtDistance(root, root->left, 1);
    
    for(Node* node:ans)
        cout << node->data << " ";
    cout << endl;
    return 0;
}