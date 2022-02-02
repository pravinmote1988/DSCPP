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
        void dfs(int node, vector<vector<int>> &adjList, vector<int> &visited, vector<int> &bfsVector) 
        {
            if(!visited[node])
            {
                bfsVector.push_back(node);
                visited[node] = 1;
                for(int vertex : adjList[node]) 
                {
                    if(!visited[vertex])
                        dfs(vertex, adjList, visited, bfsVector);
                }
            }            
        }
};

int main()
{
   // struct Edge E[] = { {1,2}, {2,3}, {3,4}, {4,5}, {5,2}, {7,8}, {8,9} };
    struct Edge E[] = { {1,2}, {2,4}, {3,5}, {4,6}, {6,7}, {7,2} };

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

    vector<int> dfsVector;
    vector<int> visited(nodes + 1, 0);

    Solution s;
    // Adjacency list is ith 0 index but the nodes are from index 1
    for(int i =1; i <= nodes; i++) 
    {
        if(!visited[i])
            s.dfs(i, adjList, visited, dfsVector);
    }

    for(int i : dfsVector)
    {
        cout << i << "";
    }
    cout << endl;

    return 0;
}