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


vector<int> getPathHelper(int** edges, int numVertex, int source, int destination, bool* visited) {
    vector<int>path;
    if (source == destination) {
        path.push_back(source);
        return path; 
    }

    visited[source] = true;
    for (int i = 0; i < numVertex; i++) {
        if (i ==  source)
            continue;
        vector<int>smallPath;
        if (!visited[i] && edges[i][source] == 1) {
            smallPath = getPathHelper(edges, numVertex, i, destination, visited);
            if (smallPath.size() > 0) {
                smallPath.push_back(source);
                return smallPath;
            }
        }
    }
    return path; // empty path
}

vector<int> getPath(int** edges, int numVertex, int source, int destination) {
    bool* visited = new bool[numVertex];
    return getPathHelper(edges, numVertex, source, destination, visited);
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

    
    int source, dest;
    cin >> source >> dest;
    vector<int>sourceToDestPath = getPath(edges, numVertices, source, dest);
    for (int i = 0; i < sourceToDestPath.size(); i++) 
        cout << sourceToDestPath[i] << " ";
    cout << endl << endl;

    // Deleting the graph
    for (int i = 0; i < numVertices; i++)
        delete [] edges[i];
    delete [] edges;
    return 0;
}