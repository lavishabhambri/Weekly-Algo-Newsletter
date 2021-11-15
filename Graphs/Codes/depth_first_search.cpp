#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
// DFS from a startVertex
void printGraphDFS(int** edges, int numVertices, int startingVertex, bool* visited) {
    cout << startingVertex << " ";
    visited[startingVertex] = true;

    for (int i = 0; i < numVertices; i++) {
        if (i == startingVertex)
            continue;
        
        if (edges[startingVertex][i] == 1 && visited[i] == false) // means connected and not visited earlier
            printGraphDFS(edges, numVertices, i, visited);
    }
}

// DFS for disconnected components
void DFS(int** edges, int numVertex) {
    bool* visited = new bool[numVertex];

    for (int i = 0; i < numVertex; i++)
        visited[i] = false;

    for (int i = 0; i < numVertex; i++) {
        if (visited[i] ==  false)
            printGraphDFS(edges, numVertex, i, visited); // startingVertex = i
    }
    delete [] visited;
}



int main()
{
    fast_cin();
    int numVertices, numEdges;
    cin >> numVertices >>  numEdges;

    // Adjacency Matrix
    int** edges = new int*[numVertices];
    for (int i = 0; i < numVertices; i++) {
        edges[i] = new int[numVertices];
        for (int j = 0; j < numVertices; j++)
            edges[i][j] = 0; // Initially all vertices are not connected
    }

    for (int i = 0; i < numEdges; i++) {
        int firstVertex, secondVertex;
        cin >> firstVertex >> secondVertex;
        edges[firstVertex][secondVertex] = 1;
        edges[secondVertex][firstVertex] = 1;
    }

    DFS(edges, numVertices);

    // Deleting the graph
    for (int i = 0; i < numVertices; i++)
        delete [] edges[i];
    delete [] edges;
    return 0;
}