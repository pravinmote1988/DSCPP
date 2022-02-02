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
        bool isCycleBfs(int nodes, vector<vector<int>> &adjList) 
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

            int count =0;

            while(!bfsQueue.empty())
            {
                int node = bfsQueue.front();
                bfsQueue.pop();

                count++;                
                for(auto vertex :adjList[node])
                {
                    indegree[vertex]--;
                    if(indegree[vertex] == 0)
                        bfsQueue.push(vertex);
                }                
            }

            return (count == nodes) ? false: true;
        }
};

int main()
{
    //struct Edge E[] = { {0,1}, {1,2}, {2,4}, {3,5}, {4,6}, {6,7}, {7,2} }; //Cycle
    struct Edge E[] = { {0,1}, {1,2}, {2,4}, {3,5}, {4,6}, {6,7} };

    //Vector of vector is used to represent the adjecency list
    vector<vector<int>> adjList;
    int nodes = 8;
    
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
    if(s.isCycleBfs(nodes, adjList))
        cout << "Cycle Detected";
    else
        cout << "Cycle Not Detected";     
    cout << endl;

    return 0;
}