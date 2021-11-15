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

void getEachConnectedComponent(int** edges, int numVertices, int startingVertex, vector<bool>&visited, vector<int>&smallAns) {
    visited[startingVertex] = true;
    smallAns.push_back(startingVertex);

    for (int i = 0; i < numVertices; i++) {
        if (i == startingVertex)
            continue;  
        if (edges[startingVertex][i] == 1 && !visited[i]) {
            getEachConnectedComponent(edges, numVertices, i, visited, smallAns);
        }
    }
}

vector<vector<int>> getConnectedComponents(int** edges, int numVertices) {
    vector<vector<int>> ans;
    vector<bool> visited(numVertices, false);
    
    for (int i = 0; i < numVertices; i++) {
        if (visited[i] == false) {
            vector<int>smallAns;
            getEachConnectedComponent(edges, numVertices, i, visited, smallAns);
            ans.push_back(smallAns);
        }
    }
    return ans;
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

    cout << "Get All Components" << endl;

    vector<vector<int>>allComponents = getConnectedComponents(edges, numVertices);
    for (int i = 0; i < allComponents.size(); i++) {
        for (int j = 0; j < allComponents[i].size(); j++) {
            cout << allComponents[i][j] << " ";
        }
        cout << endl;
    }

    // Deleting the graph
    for (int i = 0; i < numVertices; i++)
        delete [] edges[i];
    delete [] edges;
    return 0;
}