#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>

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

vector<int> bottomView(Node* root)
{
    map<int, Node*> tmap;
    queue<pair<Node*, int>> que;

    que.push({root, 0});

    while(!que.empty()) {
        auto qpair = que.front();
        que.pop();

        tmap[qpair.second]= qpair.first;

        if(qpair.first->left!= nullptr)
            que.push({qpair.first->left, qpair.second-1});

        if(qpair.first->right!= nullptr)
            que.push({qpair.first->right, qpair.second+1});
        
    }

    vector<int> ans;
    for(auto it: tmap)
        ans.push_back(it.second->data);
    return ans;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Node *root = new Node(1);
    // root->left = new Node(2);
    // root->left->left = new Node(3);
    // root->left->right = new Node(12);
    // root->left->left->right = new Node(4);
    // root->left->left->right->left = new Node(5);
    // root->left->left->right->right = new Node(6);
    // root->right = new Node(7);
    // root->right->right = new Node(8);
    // root->right->right->left = new Node(9);
    // root->right->right->left->left = new Node(10);
    // root->right->right->left->right = new Node(11);

    auto vorder = bottomView(root);

    for (auto val : vorder) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}