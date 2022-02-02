#include <vector>
#include <queue>
#include <iostream>
#include <limits.h>

using namespace std;


// Undirected Graph wih no waight, we will assume weight of each edge as 1 

// Struct Edge represents the start and end vertex
struct Edge{
	int vStart; 
	int vEnd; 
};

class Solution
{
    public:
        vector<int> bfsShortestDistance(int nodes, vector<vector<int>> &adjList, int source) 
        {
            vector<int> distance(nodes, 0);
            for(int i =0; i <nodes ; i++)
                distance[i] = INT_MAX;

            distance[source] = 0;

            queue<int> bfsQ;
            bfsQ.push(source);

            while(!bfsQ.empty())
            {
                int node = bfsQ.front();
                bfsQ.pop();
                
                for(int vertex : adjList[node])
                {
                    if(distance[node] + 1 < distance[vertex])
                    {
                        distance[vertex] = distance[node] + 1;
                        bfsQ.push(vertex);
                    }
                }
            }

            return distance;
        }
};

int main()
{
    struct Edge E[] = { {0,1}, {1,3}, {0,3}, {1,2}, {3,4}, {4,5}, {5,6}, {2,6}, {6,7}, {7,8}, {6,8}};
    // output 
    // 0 1 2 1 2 3 3 4 4
    // 0 1 2 3 4 5 6 7 8

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
        adjList[E[i].vEnd].push_back(E[i].vStart);
    }

    Solution s;
    vector<int> result = s.bfsShortestDistance(nodes, adjList, 0);

    for(int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}