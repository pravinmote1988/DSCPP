#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

// Kosaraju algorithm is used to find the strongly connected components
// Step 1 - Toposort using DFS
// Step 2 - Transpose the graph
// Step 3 - reverse DFS on the transpose graph

// Topo sort is only possible in Directed Acyclic Graph
// Struct Edge represents the start and end vertex
struct Edge{
	int vStart; 
	int vEnd; 
};

void dfs(int node, vector<vector<int>> &adjList, vector<int> &visited, stack<int> &dfsStack) 
{
    visited[node] = 1;
    for(int vertex : adjList[node]) 
    {
        if(!visited[vertex]) 
        {
            dfs(vertex, adjList, visited, dfsStack);
        }
    }
    dfsStack.push(node);          
}

void reverseDfs(int node, vector<vector<int>> &transpose, vector<int> &visited) 
{
    visited[node] = 1;
    cout << node << " ";
    for(int vertex : transpose[node]) 
    {
        if(!visited[vertex]) 
        {
            reverseDfs(vertex, transpose, visited);
        }
    }  
    cout << endl;     
}

int main()
{
    struct Edge E[] = { {1,2}, {2,3}, {3,1}, {2,4}, {4,5}};
    
    //Vector of vector is used to represent the adjecency list
    int nodes =5;
    vector<vector<int>> adjList(nodes+1, vector<int>());
    
    for(int i = 0; i < sizeof(E)/sizeof(E[0]); ++i)
    {
        adjList[E[i].vStart].push_back(E[i].vEnd);
    }

    vector<int> visited(nodes + 1, 0);
    stack <int> dfsStack;

    // Toposort
    for(int i =1; i<= nodes; i++) 
    {
        if(!visited[i])
           dfs(i, adjList, visited, dfsStack);
    }

    // Transpose
    vector<vector<int>> transpose(nodes+1, vector<int>());
    for(int i =1; i <=nodes; ++i)
    {
        visited[i] = 0;
        for(auto it : adjList[i]){
            transpose[it].push_back(i);
        }
    }

    // ReverseDfs
    for(int i =1; i <= nodes; i++) 
    {
        if(!visited[i])
           reverseDfs(i, adjList, visited);
    }
    cout << endl;

    return 0;
}