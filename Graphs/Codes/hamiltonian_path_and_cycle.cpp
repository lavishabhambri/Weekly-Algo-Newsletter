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


void printHamiltonianPathAndCycleHelper(int** edges, int numVertices, int startingVertex,  set<int>&visited, int orginalSource, string pathSoFar) {
    
    // BASE CASE
    if (visited.size() == numVertices - 1) { // means all vertices are visited
        // In above -1 is because pathSoFar means after including that element
        // whereas in the visited, upto that element (before including it)
        // So, the pathSoFar has already included the source in itself, hence its 
        // Greater than size of visited by 1. 
        
        // If there is an edge between the last and orginalSource then it is a cycle
        // Else a path
        if (edges[startingVertex][orginalSource] == 1)
            cout << "Cycle : ";
        else
            cout << "Path : ";
        cout << pathSoFar << endl;
        return;
    }

    visited.insert(startingVertex);

    for (int i = 0; i < numVertices; i++) {
        if (edges[startingVertex][i] == 1 && visited.find(i) == visited.end()) {
            printHamiltonianPathAndCycleHelper(edges, numVertices, i, visited, orginalSource /* source */, pathSoFar + to_string(i));
        }
    }
    visited.erase(startingVertex);

}

void printHamiltonianPathAndCycle(int** edges, int numVertices, int source) {
    set<int> visited;
    printHamiltonianPathAndCycleHelper(edges, numVertices, source, visited, source /* source */, to_string(source));
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

    int source;
    cin >> source;
    printHamiltonianPathAndCycle(edges, numVertices, source);

    // Deleting the graph
    for (int i = 0; i < numVertices; i++)
        delete [] edges[i];
    delete [] edges;
    return 0;
}