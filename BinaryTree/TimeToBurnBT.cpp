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


Node* MarkParentAndFindNode(Node *root, int data, unordered_map<Node*, Node*> &parent)
{   
    queue<Node*> que;
    que.push(root);
    Node* dataNode = nullptr;
    while(!que.empty())
    {
        Node *node = que.front();
        que.pop();
        if(node->data == data)
            dataNode = node;
        if(node->left != nullptr) {
            parent[node->left] = node;
            que.push(node->left);
        }
        if(node->right != nullptr) {
            parent[node->right] = node;
            que.push(node->right);
        }
    }
    return dataNode;
}

int timeToBurnAllNodes(Node *root, int data) // Max distance to any node
{    
    unordered_map<Node*, Node*> parents;
    Node *dataNode = MarkParentAndFindNode(root, data,  parents);

    unordered_map<Node*, bool> visited;
    queue<Node*> que;
    que.push(dataNode);
    int distance = 0;
    while(!que.empty())
    {
        int size = que.size();
        int flag = 0;

        for(int i = 0; i < size; i++) {
            Node *node = que.front();
            que.pop();
            visited[node] = true;

            if(node->left != nullptr && !visited[node->left]){
                que.push(node->left);
                visited[node->left] = true;
                flag = 1;
            }

            if(node->right != nullptr&& !visited[node->right]){
                que.push(node->right);
                visited[node->right] = true;
                flag = 1;
            }

            if(parents[node] != nullptr && !visited[parents[node]]){
                que.push(parents[node]);
                visited[parents[node]] = true;
                flag = 1;
            }
        }
        if(flag)
            distance++;
    }

    return distance;
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

    cout << timeToBurnAllNodes(root, 4);
    cout << endl;
    return 0;
}