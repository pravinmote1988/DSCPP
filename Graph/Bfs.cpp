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
        void bfs(int nodes, vector<vector<int>> &adjList, vector<int> &bfsVector) 
        {
            vector<int> visited(nodes+1, 0);

            for(int i =1; i <=nodes ; i++)
            {
                if(!visited[i])
                {
                    queue<int> que;
                    que.push(i);
                    visited[i] = 1;
    
                    while(!que.empty())
                    {
                        int node = que.front();
                        que.pop();
                        bfsVector.push_back(node);
        
                        for(int vertex : adjList[node])
                        {
                            if(!visited[vertex])
                            {
                                que.push(vertex);
                                visited[vertex] = 1;
                            }
                        }
                    }
                }
            }
        }
};

int main()
{
    struct Edge E[] = { {1,2}, {2,3}, {3,4}, {4,5}, {5,2}, {6,7}, {7,8}};

    //Vector of vector is used to represent the adjecency list
    vector<vector<int>> adjList;
    int nodes = 8;
    
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

    vector<int> bfsVector;

    Solution s;
    s.bfs(nodes, adjList, bfsVector);

    for(int i : bfsVector)
    {
        cout << i << "";
    }
    cout << endl;

    return 0;
}