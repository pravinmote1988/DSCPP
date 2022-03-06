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

vector<vector<int>> VerticalOrderTraversal(Node* root)
{
    // Need queue for bfs, map for storing the vertical and horizontal levels
    // vlevel, hlevel, (duplicate ordered data)node->data
    map<int, map<int, multiset<int>>> nodes;

    // Node*, vlevel, hlevel
    queue<pair<Node*, pair<int, int>>> que;
    que.push({ root, {0, 0} });

    while (!que.empty()) {
        auto pair1 = que.front();
        que.pop();

        int vlevel = pair1.second.first;
        int hlevel = pair1.second.second;
        nodes[vlevel][hlevel].insert(pair1.first->data);

        if (pair1.first->left != nullptr) {
            que.push({ pair1.first->left, {vlevel-1,hlevel+1} });
        }
        if (pair1.first->right != nullptr) {
            que.push({ pair1.first->right, {vlevel+1,hlevel+1} });
        }
    }

    vector<vector<int>> ans;
    for (auto node : nodes) {
        vector<int> vec;
        for (auto valueSet : node.second) {
            vec.insert(vec.end(), valueSet.second.begin(), valueSet.second.end());
        }
        ans.push_back(vec);
    }

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

    auto vorder = VerticalOrderTraversal(root);

    for (auto val : vorder) {
        for (auto data : val) {
            cout << data << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}