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
    struct Edge E[] = {{1,2,2}, {2,3,4}, {1,4,1}, {4,3,3}, {2,5,5}, {3,5,1}};

    //output
    // MAX  0 2 4 1 5
    // 0    1 2 3 4 5
    
    //Vector of vector is used to represent the adjecency list
    int nodes = 5;
    vector<pair<int, int>> adjList[nodes+1];
    
    for(int i =0; i < sizeof(E)/sizeof(E[0]); ++i)
    {
        adjList[E[i].vStart].push_back({E[i].vEnd, E[i].weight});
        adjList[E[i].vEnd].push_back({E[i].vStart, E[i].weight});
    }

    int source = 1;
    vector<int> distance(nodes+1, INT_MAX);
    distance[source] =0;

    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> priQue;
    priQue.push(make_pair(0, source));

    while(!priQue.empty())
    {
        pair<int, int> wu = priQue.top();
        priQue.pop();

        int nodeDistance = wu.first;
        int node = wu.second;

        for(pair<int, int> vw : adjList[node])
        {
            if(distance[vw.first] > distance[node] + vw.second)
            {
                distance[vw.first] = distance[node] + vw.second;
                priQue.push(make_pair(distance[vw.first], vw.first));
            }
        }
    }

    for(int dist : distance)
        cout << dist << " ";

    cout << endl;

    return 0;
}