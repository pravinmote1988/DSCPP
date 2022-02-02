#include <vector>
#include <queue>
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
        void toposortBfs(int nodes, vector<vector<int>> &adjList, vector<int> &toposort) 
        {
            vector<int> indegree(nodes, 0);
            queue<int> bfsQueue;

            //Calculate indegree of each node

            for(int i =0; i < nodes; ++i )
            {
                for(auto node : adjList[i])
                {
                    indegree[node]++;
                }
            }

            for(int i =0; i < nodes ; i++)
            {
                if(indegree[i] ==0)
                   bfsQueue.push(i); 
            }

            while(!bfsQueue.empty())
            {
                int node = bfsQueue.front();
                bfsQueue.pop();

                toposort.push_back(node);
                
                for(auto vertex :adjList[node])
                {
                    indegree[vertex]--;
                    if(indegree[vertex] == 0)
                        bfsQueue.push(vertex);
                }                
            }
        }
};

int main()
{
    struct Edge E[] = { {5,0}, {4,0}, {5,2}, {2,3}, {3,1}, {4,1} };

    //Vector of vector is used to represent the adjecency list
    vector<vector<int>> adjList;
    int nodes = 6;
    
    for(int i = 0; i<nodes; i++)
    {
        vector<int> vertices;
        adjList.push_back(vertices);
    }
    
    for(int i =0; i < sizeof(E)/sizeof(E[0]); ++i)
    {
        adjList[E[i].vStart].push_back(E[i].vEnd);
    }

    Solution s;
    vector<int> toposort;
    s.toposortBfs(nodes, adjList, toposort);

    for(int node : toposort)
        cout << node << " ";
    cout << endl;

    return 0;
}