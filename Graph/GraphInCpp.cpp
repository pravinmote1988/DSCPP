#include <vector>

using namespace std;

// Struct Edge represents the start and end vertex
struct Edge{
	int vStart; 
	int vEnd; 
};

int main()
{
    struct Edge E[] = { {1,2}, {2,3}, {3,4}, {4,5}, {5,2}, {6,7}, {7,8}};

    //Vector of vector is used to represent the adjecency list
    vector<vector<int>> adjList;
    
    for(int i =0; i < sizeof(E)/sizeof(E[0]); ++i)
    {
        adjList[E[i].vStart].push_back(E[i].vEnd);
        adjList[E[i].vEnd].push_back(E[i].vStart);
    }

    return 0;
}