#include <vector>
#include <set>
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
        void articulationPoints(int node, int parent, vector<vector<int>> &adjList, vector<int> &visited,
                          int timer, vector<int> &tin, vector<int> &low, set<int> &artPoints) 
        {
            visited[node] = 1;
            tin[node] = low[node] = timer++;
            int children =0;
            for(int vertex : adjList[node]) 
            {
                if(vertex == parent)
                    continue;
                if(!visited[vertex]) 
                {
                    articulationPoints(vertex, node, adjList, visited, timer, tin, low, artPoints);
                    low[node] = min(low[node], low[vertex]);
                    if(low[vertex] >= tin[node] && parent != -1)
                        artPoints.insert(node);
                    
                    children++;
                }
                else{
                    low[node] = min(low[node], tin[vertex]);
                }                    
            }
            if(parent == -1 && children > 1)
                artPoints.insert(node);           
        }
};

int main()
{
    //struct Edge E[] = { {1,2}, {2,3}, {3,4}, {4,5}, {5,2}, {7,8}, {8,9} };
    struct Edge E[] = { {1,2}, {2,3}, {3,4}, {4,5}, {3,1}};

    // Output
    // 3
    // 4

    //Vector of vector is used to represent the adjecency list
    int nodes = 5;
    vector<vector<int>> adjList(nodes+1, vector<int>());
    
    for(int i =0; i < sizeof(E)/sizeof(E[0]); ++i)
    {
        adjList[E[i].vStart].push_back(E[i].vEnd);
        adjList[E[i].vEnd].push_back(E[i].vStart);
    }

    vector<int> visited(nodes + 1, 0);

    Solution s;
    vector<int> tin(nodes + 1, 0);
    vector<int> low(nodes + 1, 0);
    set<int> artpoints;

    int timer = 1;
    for(int i =1; i <= nodes; i++) 
    {
        if(!visited[i])
           s.articulationPoints(i, -1, adjList, visited, timer, tin, low, artpoints);
    }
    
    for(int node: artpoints)
        cout << node << endl;
    cout << endl;

    return 0;
}