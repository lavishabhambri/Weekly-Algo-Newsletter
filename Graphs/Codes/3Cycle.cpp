#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

int getNumberOf3Cycles(vector<vector<int>>edges) {
    int n = edges.size();
    unordered_map<int, pair<int, int>>m;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && edges[i][j] == 1) { 
                for (int k = 0; k < n; k++) {
                    if (edges[j][k] == 1 && k != i && k != j) {
                        int adjAdjVertex = k;
                        if (edges[i][adjAdjVertex] == 1) {

                            // Instead of storing in map
                            // Do count++; & at the end just return count/6 as for the 
                            // 3 vertices of the 3 cycle we are just changing the order
                            // 3! extra ways for each cycle are added, hence divide by 3!
                            int first = min(i, min(j, k));
                            int second, third;
                            if (first == i) {
                                if (j < k) {
                                    second = k;
                                    third = j;
                                }else {
                                    second = j;
                                    third = k;
                                }
                            }else if (first == j) {
                                if (i < k) {
                                    second = k;
                                    third = i;
                                }else {
                                    second = i;
                                    third = k;
                                }
                            }else {
                                if (j < i) {
                                    second = i;
                                    third = j;
                                }else {
                                    second = j;
                                    third = i;
                                }
                            }

                            m[first] = make_pair(second, third);
                        }
                            
                    }
                }
            }
        }
    }
    return m.size();
}
 
int main()
{
    fast_cin();
    int n, m;
    cin >> n >> m;
    vector<vector<int>>edges;
    for (int i = 0; i < n; i++) {
        vector<int>v1(n, 0);
        edges.push_back(v1);
    }

    for (int i = 0; i < m; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    } 

    cout << getNumberOf3Cycles(edges) << endl;
    return 0;
}




