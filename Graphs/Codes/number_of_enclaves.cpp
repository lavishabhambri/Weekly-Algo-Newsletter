#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
void dfs(vector<vector<int>>&v,int i, int j, int n, int m){
    if (i < 0 || j < 0 || i >= n || j >= m || v[i][j] == 0) 
        return;
    
    v[i][j] = 0; // make it visited
    dfs(v, i + 1, j, n, m);
    dfs(v, i - 1, j, n, m);
    dfs(v, i, j + 1, n, m);
    dfs(v, i, j - 1, n, m);
}


int numberOfEnclaves(vector<vector<int>>&v, int n, int m) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                if (v[i][j] == 1)
                    dfs(v, i, j, n, m);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 1)
                count++;
        }
    }
    return count;
}
 
int main()
{
    fast_cin();
    int n, m;
    cin >> n >> m;
    vector<vector<int>>v;
    for (int i = 0; i < n; i++) {
        vector<int>v1(m);
        v.push_back(v1);
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    cout << numberOfEnclaves(v, n, m);
    
    return 0;
}