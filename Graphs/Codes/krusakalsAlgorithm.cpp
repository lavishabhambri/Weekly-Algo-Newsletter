#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

class Edge{
    public:
    int source;
    int dest;
    int weight;

    // Edge(int s, int d, int w) {
    //     source = s;
    //     dest = d;
    //     weight = w;
    // }
};

bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

int findTopParent(int v, int *parent) {
    // Parent is found when the index == value
    if (v == parent[v])
        return v;
    return findTopParent(parent[v], parent);
}

void kruskalsAlgorithm(Edge* input, int vertices, int edges) {
    // Sort the array on basis of weights
    sort(input, input + edges, compare);

    // Create output MST - size = vertices - 1
    Edge* output = new Edge[vertices - 1];
    int count = 0; // Stores the total no. of vertices present currently
    int i = 0;
    int* parent = new int[vertices];
    for (int i = 0; i < vertices; i++)
        parent[i] = i;
    
    while (count != vertices - 1) {
        Edge currentEdge = input[i];

        // Check if we can include the current edge or not
        int sourceParent = findTopParent(currentEdge.source, parent);
        int destParent = findTopParent(currentEdge.dest, parent);

        if (sourceParent != destParent) { // safe to add
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }

        i++;
    }

    // Print MST
    for (int i = 0; i < vertices - 1; i++) {
        if (output[i].source < output[i].dest) 
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
        else    
            cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
    }
}
 
int main()
{
    fast_cin();
    // Take input
    int vertices, edges;
    cin >> vertices >> edges;
    Edge *input = new Edge[edges];

    for (int i = 0; i < edges; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskalsAlgorithm(input, vertices, edges);

    return 0;
}