#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

// Struct Edge represents the start and end vertex
struct Edge{
	int vStart; 
	int vEnd; 
    int weight;
};

int main()
{
    struct Edge E[] = {{0,1,2}, {1,2,3}, {2,4,7}, {1,4,5}, {1,3,8}, {0,3,6}};

    //output
    // Parent   -1   0 1 0 1 
    // Nodes    0    1 2 3 4 

    // Node: 0 Parent: -1
    // Node: 1 Parent: 0
    // Node: 2 Parent: 1
    // Node: 3 Parent: 0
    // Node: 4 Parent: 1
    
    //Vector of vector is used to represent the adjecency list
    const int nodes = 5;
    vector<pair<int, int>> adjList[nodes];
    
    for(int i =0; i < sizeof(E)/sizeof(E[0]); ++i)
    {
        adjList[E[i].vStart].push_back({E[i].vEnd, E[i].weight});
        adjList[E[i].vEnd].push_back({E[i].vStart, E[i].weight});
    }

    int parent[nodes];
    int mst[nodes];
    int key[nodes];

    for(int i =0; i < nodes; ++i)
        key[i] = INT_MAX, mst[i]=false, parent[i]=-1;

    key[0] =0;
    
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> priQ;

    priQ.push(make_pair(0,0));

    for(int i =0; i < nodes-1; i++)
    {
        int node = priQ.top().second;
        priQ.pop();

        mst[node]= true;

        for(pair<int,int> vw : adjList[node])
        {
            int v = vw.first;
            int weight = vw.second;

            if(!mst[v] && key[v] > weight){
                key[v] = weight;
                priQ.push({weight, v});
                parent[v] = node;
            }
        }
    }

    for(int i = 0; i <nodes; i++)
        cout << "Node: " << i << " Parent: " << parent[i] << endl;

    cout << endl;
}