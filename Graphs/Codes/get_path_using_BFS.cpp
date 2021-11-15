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

// We will keep a map, that tells us which element is entered by which element
// We won't add anything for the source element.
vector<int> getPathBFShelper(int** edges, int numVertices, int source, int destination, bool* visited) {
    map<int, int> getPairs;
    vector<int> ans;
    bool destPresent = false;
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty() && !destPresent) {
        int front = q.front();
        // cout << front << " ";
        
        q.pop();
        for (int i = 0; i < numVertices; i++) {
            if (i == front)
                continue;
            
            if (edges[front][i] == 1 && visited[i] == false) {
                getPairs[i] = front;
                q.push(i);
                visited[i] = true;
                if (i == destination) {
                    destPresent = true;
                    break;
            }
            }
        }
    }

    if (!destPresent)
        return ans;
    
    int val = destination;
    ans.push_back(val);
    while (val != source) {
        val = getPairs[val];
        ans.push_back(val);
    }
    return ans;
}

vector<int> getPathBFS(int** edges, int numVertex, int source, int destination) {
    bool* visited = new bool[numVertex];
    return getPathBFShelper(edges, numVertex, source, destination, visited);
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
    vector<int>sourceToDestPath = getPathBFS(edges, numVertices, source, dest);
    for (int i = 0; i < sourceToDestPath.size(); i++) 
        cout << sourceToDestPath[i] << " ";
    cout << endl << endl;

    // Deleting the graph
    for (int i = 0; i < numVertices; i++)
        delete [] edges[i];
    delete [] edges;
    return 0;
}