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

class graphBipartite{
    public:
    int vertex;
    int level;

    graphBipartite(int vertex, int level) {
        this->vertex = vertex;
        this->level = level;
    }
};

bool isComponentBipartite(int** edges, int numVertices, int startingVertex, vector<int>visited) {
    queue<graphBipartite> pendingNodes;
    pendingNodes.push(graphBipartite(startingVertex, 0)); // initially level = 0

    while (pendingNodes.size() > 0) {
        graphBipartite removedVertex = pendingNodes.front();
        pendingNodes.pop();

        if (visited[removedVertex.vertex] != -1) { // means not visited
            int oldLevel = visited[removedVertex.vertex];
            int newLevel = removedVertex.level;
            if (oldLevel % 2 != newLevel % 2) // means cycle is present
                return false;
        } else 
            visited[removedVertex.vertex] = removedVertex.level;
        
        for (int i = 0; i < numVertices; i++) {
            // means edge exists and its neighbour is not earlier visited
            if (edges[i][removedVertex.vertex] == 1 && visited[i] == -1) {
                pendingNodes.push(graphBipartite(i, removedVertex.level + 1));
            }
        }
    }
    return true;
}

bool isGraphBipartite(int** edges, int numVertices) {
    // here the visited array stores levels 
    // Initially visited array stores -1 => no level
    vector<int>visited(numVertices,  -1); 
    for (int i = 0; i < numVertices; i++) {
        if (visited[i] == -1) {
            if (!isComponentBipartite(edges, numVertices, i, visited)) 
                return false;
        }
    }
    return true;
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
        int firstVertex, secondVertex, w;
        cin >> firstVertex >> secondVertex >> w;
        edges[firstVertex][secondVertex] = 1;
        edges[secondVertex][firstVertex] = 1;
    }

    isGraphBipartite(edges, numVertices) == 0 ? cout << "false" : cout << "true" << endl;

    // Deleting the graph
    for (int i = 0; i < numVertices; i++)
        delete [] edges[i];
    delete [] edges;
    return 0;
}