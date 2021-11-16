#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

int findUnique(vector<int>v) {
    int n = v.size();
    int finalAns = 0;
    for (int i = 0; i <n; i++)
        finalAns ^= v[i];
    return finalAns;
}
 
int main()
{
    fast_cin();
    int n;
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << findUnique(v) << endl;
    return 0;
}