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
        bool cycleInBfs(int nodes, vector<vector<int>> &adjList) 
        {
            vector<int> visited(nodes+1, 0);

            for(int i =1; i <=nodes ; i++)
            {
                if(!visited[i])
                {
                    queue<pair<int, int>> que;
                    que.push({i, -1});
                    visited[i] = 1;
    
                    while(!que.empty())
                    {
                        pair<int, int> nodePair = que.front();
                        que.pop();

                        int node = nodePair.first;
                        int parent = nodePair.second;

                        for(int vertex : adjList[node])
                        {
                            if(!visited[vertex])
                            {
                                visited[vertex] = 1;
                                que.push(pair<int, int>{vertex, node});
                            }
                            else if(vertex != parent){
                                return true;
                            }
                        }
                    }
                }
            }
            return false;
        }
};

int main()
{
    struct Edge E[] = { {1,2}, {2,3}, {3,4}, {4,5}, /*{5,2},*/ {6,7}, {7,8}};

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
    auto result = s.cycleInBfs(nodes, adjList);

    if (result)
        cout << "Cycle detected";
    else
        cout << "Cycle not detected";
    cout << endl;

    return 0;
}