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

int findParent(int node, vector<int> &parent)
{
    if(node == parent[node])
        return node;
    
    return parent[node] = findParent(parent[node], parent);
}

void unionn(int u,int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[u] > rank[v]) {
        parent[v] = u;
    }else{
        parent[v] =u;
        rank[u]++;
    }
}

bool comp(node u, node v)
{
    return u.wt < v.wt;
}

int main()
{
    struct Edge E[] = {{1,5,4}, {1,4,1}, {5,4,9}, {4,3,5}, {4,2,3}, {1,2,2}, {3,2,3}, {3,6,8}, {2,6,7}};
    const int nodes = 6;

    // Output
    // cost: 17
    // 1<->4
    // 1<->2
    // 3<->2
    // 1<->5
    // 2<->6

    vector<node> edges;
    
    for(int i =0; i < sizeof(E)/sizeof(E[0]); i++) {
        int u = E[i].vStart;
        int v = E[i].vEnd;
        int w = E[i].weight;
        edges.push_back(node(u,v,w));
    }

    sort(edges.begin(), edges.end(), comp);

    // Make disjoint set
    vector<int> parent(nodes+1);
    for(int i = 0; i <=nodes; i++) {
        parent[i] = i;
    }

    vector<int> rank(nodes+1, 0);

    vector<pair<int, int>> mst;
    int cost = 0;
    for(node dsnode: edges){
        int u = dsnode.u;
        int v = dsnode.v;
        if(findParent(u, parent) != findParent(v, parent)){
            cost += dsnode.wt;
            mst.push_back({u,v});
            unionn(u, v, parent, rank);
        }
    }

    cout << "cost: " << cost << endl;

    for(auto it: mst)
        cout << it.first << "<->" << it.second << endl;
    
    return 0;
}