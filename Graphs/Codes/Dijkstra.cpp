#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

int findMinVertex(int* distance, bool* visited, int n) {
    int minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && (minIndex == -1 || distance[minIndex] > distance[i]))
            minIndex = i;
    }
    return minIndex;
} 

void dijkstra(int** edges, int n) {
    // Create 2 arrays
    bool* visited = new bool[n];
    int* distance = new int[n];

    // Make them unvisited & weight as INT_MAX
    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    // For the source node, update the distance
    distance[0] = 0;

    for (int i = 0; i < n; i++) {

        // Find the vertex that is minimum & unvisited
        int minUnvisitedVertex = findMinVertex(distance, visited, n);

        // Mark it as visited
        visited[minUnvisitedVertex] = true;

        // Explore the unvisited neighbours of the minVertex
        for (int j = 0; j < n; j++) {
            if (edges[j][minUnvisitedVertex] != 0 && !visited[j]) {
                int dist = distance[minUnvisitedVertex] + edges[j][minUnvisitedVertex];

                // Check if we need to update the parent & weight of this neighbour
                if (dist < distance[j]) {
                    distance[j] = dist;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << " " << distance[i] << endl;
    }
    return;
}
 
int main()
{
    fast_cin();
    int n, e; // n - vertices, e - edges
    cin >> n >> e;
    int** edges = new int*[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        int source, dest, weight;
        cin >> source >> dest >> weight;
        edges[source][dest] = weight;
        edges[dest][source] = weight;
    }

    dijkstra(edges, n);
    return 0;
}

