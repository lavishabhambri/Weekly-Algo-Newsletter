#include<bits/stdc++.h>
using namespace std;

bool shortestPaths(vector<vector<int>>v, int n, int m) {
    vector<int>path(n, INT_MAX);
    path[0] = 0;
    
    // Perform n - 1 iterations
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int first = v[j][0];
            int second = v[j][1];
            int weight = v[j][2];
            
            if (path[first] == INT_MAX)
                continue;
            
            if (path[first] + weight < path[second])
                path[second] = path[first] + weight;
        }
    }
    
    // Perform an extra iteration. But first store the vector so that we can check if any updation occured after this vth iteration.
    vector<int>path2 = path;
    for (int j = 0; j < m; j++) {
        int first = v[j][0];
        int second = v[j][1];
        int weight = v[j][2];
        
        if (path[first] == INT_MAX)
            continue;
        
        if (path[first] + weight < path[second])
            path[second] = path[first] + weight;
    }
    
    for (int i = 0; i < m; i++) {
        if (path2[i] != path[i])
            return true;
    }
    return false;
    
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>v(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
       cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    
    cout << shortestPaths(v, n, m) << endl;
    
}