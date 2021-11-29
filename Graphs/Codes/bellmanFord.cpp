#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPaths(vector<vector<int>>v, int n, int m) {
    vector<int>path(n, INT_MAX);
    path[0] = 0;
    
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
    return path;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>v(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
       cin >> v[i][0] >> v[i][1] >> v[i][2]; 
       v[i][0] -= 1;
       v[i][1] -= 1;
    }
    
    vector<int>ans = shortestPaths(v, n, m);
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] != INT_MAX)
            cout << ans[i] << " ";
        else
            cout << 1000000000 << " ";
    }
    cout << endl;
    
}