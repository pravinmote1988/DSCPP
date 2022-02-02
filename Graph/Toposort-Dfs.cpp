#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

// Topo sort is only possible in Directed Acyclic Graph
// Struct Edge represents the start and end vertex
struct Edge{
	int vStart; 
	int vEnd; 
};

class Solution
{
    public:
        void toposort(int node, vector<vector<int>> &adjList, vector<int> &visited, stack<int> &dfsStack) 
        {
            if(!visited[node])
            {
                visited[node] = 1;
                for(int vertex : adjList[node]) 
                {
                    if(!visited[vertex]) 
                    {
                        toposort(vertex, adjList, visited, dfsStack);
                    }
                }
            }
            dfsStack.push(node);          
        }
};

int main()
{
    //struct Edge E[] = { {1,2}, {2,3}, {3,4}, {4,5}, {5,2}, {7,8}, {8,9} };
    struct Edge E[] = { {5,0}, {4,0}, {5,2}, {2,3}, {3,1}, {4,1} };

    //Vector of vector is used to represent the adjecency list
    vector<vector<int>> adjList;
    int nodes = 9;
    
    for(int i = 0; i<nodes; i++)
    {
        vector<int> vertices;
        adjList.push_back(vertices);
    }
    
    for(int i =0; i < sizeof(E)/sizeof(E[0]); ++i)
    {
        adjList[E[i].vStart].push_back(E[i].vEnd);
    }

    vector<int> visited(nodes + 1, 0);
    stack <int> dfsStack;

    Solution s;
    auto result = false;
    // Adjacency list is ith 0 index but the nodes are from index 1
    for(int i =0; i < nodes; i++) 
    {
        if(!visited[i])
           s.toposort(i, adjList, visited, dfsStack);
    }

    while(!dfsStack.empty()) 
    {
        cout << dfsStack.top() << " ";
        dfsStack.pop();
    }
    cout << endl;

    return 0;
}