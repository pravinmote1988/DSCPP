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
        bool checkBipartiteBfs(int nodes, vector<vector<int>> &adjList) 
        {
            vector<int> color(nodes+1, -1);

            for(int i =1; i <=nodes ; i++)
            {
                if(color[i] == -1)
                {
                    queue<int> que;
                    que.push(i);
                    color[i] = 1;
    
                    while(!que.empty())
                    {
                        int node = que.front();
                        que.pop();

                        for(int vertex : adjList[node])
                        {
                            if(color[vertex] == -1)
                            {
                                color[vertex] = 1 - color[node];
                                que.push(vertex);
                            }
                            else if(color[vertex] == color[node])
                                return false;
                        }
                    }
                }
            }
            return true;
        }
};

int main()
{
    //struct Edge E[] = { {1,2}, {2,3}, {3,4}, {4,5}, {5,2}, {6,7}, {7,8}}; // Bipertite
    struct Edge E[] = { {1,2}, {2,3}, {3,4}, {4,5}, {5,6}, {6,2}, {7,8}}; //Not Bipertite

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

    Solution s;
    auto result = s.checkBipartiteBfs(nodes, adjList);

    if (result)
        cout << "Bipartite";
    else
        cout << "Not Bipartite";
    cout << endl;

    return 0;
}