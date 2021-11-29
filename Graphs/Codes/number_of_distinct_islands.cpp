#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

string psf = ""; // pathSoFar 
void dfs(vector<vector<int>>&v,int i, int j, int n, int m){
    
    v[i][j] = 0; // make it visited

    // UPWARDS
    if (i - 1 >= 0 && v[i - 1][j] == 1) {
        psf += 'u';
        dfs(v, i - 1, j, n, m);
    }

    // RIGHT
    if (j + 1 < m && v[i][j + 1] == 1) {
        psf += 'r';
        dfs(v, i, j + 1, n, m);
    }

    // DOWNWARDS
    if (i + 1 < n && v[i + 1][j] == 1) {
        psf += 'd';
        dfs(v, i + 1, j, n, m);
    }

    // LEFT
    if (j - 1 >= 0 && v[i][j - 1] == 1) {
        psf += 'l';
        dfs(v, i, j - 1, n, m);
    }

    psf += 'z'; // as we are backtracking
}


int numberOfDistinctIslands(vector<vector<int>>&v, int n, int m) {
    set<string>s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 1) {
                psf = "";
                psf += 'x'; // as calling dfs
                dfs(v, i, j, n, m);
                s.insert(psf);
            }
        }
    }
    return s.size();

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

    cout << numberOfDistinctIslands(v, n, m);
    
    return 0;
}