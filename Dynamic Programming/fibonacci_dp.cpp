#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
// TC = O(2^n)
int fib(int n) {
    if (n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// TC = O(n)
int fib_dp(int n, vector<int>& arr) {
    if (n == 0 || n == 1)
        return n;
    if (arr[n] > 0) // means answer already present
        return arr[n];
    arr[n] = fib_dp(n - 1, arr) + fib_dp(n - 2, arr);
    return arr[n];
}

// TC = O(n)
int fib_iterative(int n) {
    vector<int> arr(n + 1);
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++) 
        arr[i] = arr[i - 1] + arr[i - 2];
    return arr[n];
}
 
int main()
{
    fast_cin();
    int n;
    cin >> n;
    
    vector<int> arr(n + 1, 0);
    cout << "Dp : " << fib_dp(n, arr) << endl;
    cout << "Iterative : " << fib_iterative(n) << endl;
    return 0;
}