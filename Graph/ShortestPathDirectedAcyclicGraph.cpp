#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <limits.h>

using namespace std;

// Topo sort is only possible in Directed Acyclic Graph
// Struct Edge represents the start and end vertex
struct Edge{
	int vStart; 
	int vEnd;
    int weight; 
};

class Solution
{
    private:
        void toposort(int node, vector<pair<int, int>> adjList[], vector<int> &visited, stack<int> &dfsStack) 
        {
            if(!visited[node])
            {
                visited[node] = 1;
                for(pair<int, int> vw : adjList[node]) 
                {
                    if(!visited[vw.first]) 
                    {
                        toposort(vw.first, adjList, visited, dfsStack);
                    }
                }
            }
            dfsStack.push(node);          
        }

    public:
        vector<int> shortestDistance(int nodes, vector<pair<int, int>> adjList[], int source)
        {
            vector<int> visited(nodes, 0);
            stack<int> dfsStack;
            for(int i =0; i < nodes; i++) 
            {
                if(!visited[i])
                    toposort(i, adjList, visited, dfsStack);
            }

            vector<int> distance(nodes, INT_MAX);
            distance[source] = 0;
            while(!dfsStack.empty())
            {
                int node = dfsStack.top();
                dfsStack.pop();

                if(distance[node] == INT_MAX)
                    continue;

                for(pair<int, int> vw : adjList[node])
                {
                    if(distance[vw.first] > distance[node] + vw.second)
                        distance[vw.first] = distance[node] + vw.second;
                }
            }
            return distance;
        }
};

int main()
{
    struct Edge E[] = { {0,1,2}, {1,2,3}, {2,3,6}, {0,4,1}, {4,5,4}, {5,3,1}, {4,2,2}};

    //output
    // 0 2 3 6 1 5
    // 0 1 2 3 4 5
    
    //Vector of vector is used to represent the adjecency list
    int nodes = 6;
    vector<pair<int, int>> adjList[nodes];
    
    for(int i =0; i < sizeof(E)/sizeof(E[0]); ++i)
    {
        adjList[E[i].vStart].push_back({E[i].vEnd, E[i].weight});
    }

    vector<int> visited(nodes + 1, 0);
    stack <int> dfsStack;

    Solution s;
    auto result = s.shortestDistance(nodes, adjList, 0);

    for(auto node : result)
        cout << node << " ";
    cout << endl;

    return 0;
}