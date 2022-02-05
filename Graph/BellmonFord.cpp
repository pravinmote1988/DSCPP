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

// Disjoint set data struture
struct node {
    int u;
    int v;
    int wt;

    node(int first, int second, int weight){
        u = first;
        v = second;
        wt = weight;
    }
};

int main()
{
    // Shortest distance case
    //struct Edge E[] = {{0,1,5}, {1,2,-2}, {1,5,-3}, {5,3,1}, {3,2,6}, {2,4,3}, {3,4,-2}};
    // Output - shortest distance
    // Node: 0 distance: 0
    // Node: 1 distance: 5
    // Node: 2 distance: 3
    // Node: 3 distance: 3
    // Node: 4 distance: 1
    // Node: 5 distance: 2

    // Negative cycle test
    struct Edge E[] = {{0,1,5}, {2,1,-2}, {1,5,-3}, {5,3,-1}, {3,2,-6}, {2,4,3}, {3,4,-2}};
    // Output - Negative cycle
    

    const int nodes = 6;
    vector<node> edges;
    
    for(int i =0; i < sizeof(E)/sizeof(E[0]); i++) {
        int u = E[i].vStart;
        int v = E[i].vEnd;
        int w = E[i].weight;
        edges.push_back(node(u,v,w));
    }

    int source = 0;
    vector<int> distance(nodes, INT_MAX);
    distance[source] = 0;

    for(int i =1; i< nodes-1; i++)
    {
        for(node edge: edges){
            if(distance[edge.u] + edge.wt < distance[edge.v]){
                distance[edge.v] = distance[edge.u]+edge.wt;
            }
        }
    }

    bool isNegativeCycle = false;
    for(node edge: edges){
        if(distance[edge.u] + edge.wt < distance[edge.v]){
            cout << "Negative cycle " << endl;
            isNegativeCycle = true;
            break;
        }
    }

    if(!isNegativeCycle){
        for(int i=0; i < nodes; i++){
            cout << "Node: " << i << " distance: " << distance[i] << endl;
        }
    }
}