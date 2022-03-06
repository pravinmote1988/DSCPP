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

string serialize(Node *root)
{    
    if(root == nullptr)
        return "";

    string ser;
    queue<Node*> que;
    que.push(root);

    while(!que.empty())
    {
        Node* node = que.front();
        que.pop();

        if(node == nullptr) ser.append("#");
        else ser.append(to_string(node->data));

        if(node != nullptr)
        {
            que.push(node->left);
            que.push(node->right);
        }
    }
    cout << "Tree serialized " << ser;
    return ser;
}

Node *deserialize(string ser)
{
    int i = 0;
    auto data = atoi(ser.substr(i, 1).c_str());
    Node *root = new Node(data);

    queue<Node*> que;
    que.push(root);

    while(!que.empty())
    {
        Node* node = que.front();
        que.pop();

        string next = ser.substr(++i, 1);
        if(next == string("#")) 
            node->left = nullptr;
        else{
            node->left= new Node(atoi(next.c_str()));
            que.push(node->left);
        }

        string next1 = ser.substr(++i, 1);
        if(next1 == string("#")) 
            node->right = nullptr;
        else{
            node->right= new Node(atoi(next1.c_str()));
            que.push(node->right);
        }
    }

    return root;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    //root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    auto ans = serialize(root); // 1234#67######
    cout << endl;

    Node *root1 = deserialize(ans);

    serialize(root1); // 1234#67######
    cout << endl;
    return 0;
}