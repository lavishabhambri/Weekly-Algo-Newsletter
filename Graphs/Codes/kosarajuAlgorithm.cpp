#include<bits/stdc++.h>
using namespace std;

void dfs1(vector<vector<int>>graph, int src, stack<int>&st, vector<bool>&visited) {
    visited[src] = true;
    vector<int>nbrs = graph[src];
    for (int nbr : nbrs) {
        if (!visited[nbr]) {
            dfs1(graph, nbr, st, visited);
        }
    }
    st.push(src); // Insert while backtracking
}

void dfs2(vector<vector<int>> graph, int src, vector<bool>&visited) {
    visited[src] = true;
    vector<int>nbrs = graph[src];
    for (int nbr : nbrs) {
        if (!visited[nbr]) {
            dfs2(graph, nbr, visited);
        }
    }
}

int numberOfSCC(vector<vector<int>>graph) {
    int n = graph.size();
    stack<int>st;
    vector<bool>visited(n, false);
    
    for (int i = 0; i < n; i++) {
        vector<int>nbrs = graph[i];
        for (int nbr : nbrs) {
            if (!visited[nbr])
                dfs1(graph, nbr, st, visited);
        }
    }
    
    // Now reverse the graph
    vector<vector<int>>n_graph(graph.size());
    for (int i = 0; i < n; i++) {
        vector<int>nbrs = graph[i];
        for (int nbr : nbrs) {
            n_graph[nbr].push_back(i);
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) 
        visited[i] = false;
        
    while(st.size() > 0) {
        // cout << st.size() << " ";
        int rem = st.top();
        st.pop();
        if (!visited[rem]) {
            dfs2(n_graph, rem, visited);
            ans++;
        }
    }
    return ans;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>v(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
    }
    
    cout << numberOfSCC(v);
    
}