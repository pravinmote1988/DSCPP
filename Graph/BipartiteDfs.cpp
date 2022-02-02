#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// Struct Edge represents the start and end vertex
struct Edge{
	int vStart; 
	int vEnd; 
};

class Solution
{
    public:
        bool bipartiteDfs(int node, vector<vector<int>> &adjList, vector<int> &color) 
        {
            if(color[node] == -1) 
                color[node] = 1;
            for(int vertex : adjList[node]) 
            {
                if(color[vertex] == -1) 
                {
                    color[vertex] = 1 - color[node];
                    if(!bipartiteDfs(vertex, adjList, color))
                        return false;
                }
                else if(color[vertex] == color[node])
                    return false;
            }
            return true;            
        }
};

int main()
{
    struct Edge E[] = { {1,2}, {2,3}, {3,4}, {4,5}, {5,2}, {6,7}, {7,8}}; // Bipertite
    //struct Edge E[] = { {1,2}, {2,3}, {3,4}, {4,5}, {5,6}, {6,2}, {7,8}}; //Not Bipertite
    //struct Edge E[] = { {1,2}, {2,3}, {3,1}}; //Not Bipertite

    //Vector of vector is used to represent the adjecency list
    vector<vector<int>> adjList;
    int nodes = 9;
    
    for(int i = 0; i<=nodes; i++)
    {
        vector<int> vertices;
        adjList.push_back(vertices);
    }
    
    for(int i =0; i < sizeof(E)/sizeof(E[0]); ++i)
    {
        adjList[E[i].vStart].push_back(E[i].vEnd);
        adjList[E[i].vEnd].push_back(E[i].vStart);
    }

    vector<int> color(nodes + 1, -1);

    Solution s;
    auto result = false;
    // Adjacency list is ith 0 index but the nodes are from index 1
    for(int i =1; i <= nodes; i++) 
    {
        if(color[i] == -1)
           result = s.bipartiteDfs(i, adjList, color);
        if(!result)
                break;
    }

    if (result)
        cout << "Bipartite";
    else
        cout << "Not Bipartite";
    cout << endl;

    return 0;
}