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

// BFS from a startVertex
void printGraphBFS(int** edges, int numVertices, int startingVertex, bool* visited) {
    queue<int> q;
    q.push(startingVertex);
    visited[startingVertex] = true;

    while (!q.empty()) {
        int front = q.front();
        cout << front << " ";
        
        q.pop();
        for (int i = 0; i < numVertices; i++) {
            if (i == front)
                continue;
            
            if (edges[front][i] == 1 && visited[i] == false) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return;
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

// BFS for disconnected components
void BFS(int** edges, int numVertex) {
    bool* visited = new bool[numVertex];

    for (int i = 0; i < numVertex; i++)
        visited[i] = false;

    for (int i = 0; i < numVertex; i++) {
        if (visited[i] ==  false)
            printGraphBFS(edges, numVertex, i, visited); // startingVertex = i
    }
    delete [] visited;
}

void printAllPathsHelper(int**edges, int numVertex, int source, int destination, vector<bool> visited, string pathSoFar) {
    if (source == destination) { 
        cout << pathSoFar << endl;
        return;
    }

    visited[source] = true;
    for (int i = 0; i < numVertex; i++) {
        if (edges[source][i] == 1 && !visited[i]) {
            printAllPathsHelper(edges, numVertex, i, destination, visited, pathSoFar + to_string(i));
        }
    }
    visited[source] = false; // IMPORTANT - As source can be a part of multiple paths
}

void printAllPaths(int**edges, int numVertex, int source, int destination) {
    vector<bool>visited(numVertex);
    for (int i = 0; i < numVertex; i++)
        visited[i] = false;
    printAllPathsHelper(edges, numVertex, source, destination, visited, to_string(source));
    
}


// 8
// 9
// 0 4
// 0 5
// 4 3
// 5 6
// 3 2
// 3 1
// 3 6
// 6 7
// 2 1 
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

    int source, destination;
    cin >> source >>  destination;
    printAllPaths(edges, numVertices, source, destination);

    // Deleting the graph
    for (int i = 0; i < numVertices; i++)
        delete [] edges[i];
    delete [] edges;
    return 0;
}