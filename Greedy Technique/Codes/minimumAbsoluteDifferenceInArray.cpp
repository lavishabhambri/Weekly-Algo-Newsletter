#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

int minDifference(vector<int>arr) {
    int n = arr.size();

    // Sort the array
    sort(arr.begin(), arr.end());

    // Maintain ans
    int minDiff = INT_MAX;
    // Find consecutive differences
    for (int i = 0; i < n - 1; i++) {
        int diff = arr[i + 1] - arr[i]; // This is absolute only as arr[i+1] > arr[i]
        if (minDiff > diff)
            minDiff = diff;
    }
    return minDiff;
}
 
int main()
{
    fast_cin();
    int n;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minDifference(arr);
    return 0;
}