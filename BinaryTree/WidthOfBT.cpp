#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
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

int width(Node *root)
{    
    if(root == nullptr)
        return 0;
    queue<pair<Node*, int>> que;
    que.push({root, 0});
    int ans = 0;

    while(!que.empty()) 
    {
        int size = que.size();

        int level = que.front().second;
        int first, last;
        for(int i = 0; i < size; i++)
        {
            Node *node = que.front().first;

            int index = que.front().second - level;
            que.pop();

            if(i==0) first = index;
            if(i == size-1) last = index;
            if(node->left != nullptr)
                que.push({node->left, index*2+1});

            if(node->right != nullptr)
                que.push({node->right, index*2+2});
        }
        ans = max(ans, last-first+1);
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

    cout << width(root);
    
    cout << endl;
    return 0;
}