#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
int staircase_steps(int n) {
    if (n == 0 || n == 1)
        return 1; // only 1 way
    
    if (n == 2)
        return 2; // as we have 2 ways -> 11 or 2
        
    return staircase_steps(n - 1) + staircase_steps(n - 2) + staircase_steps(n - 3);
}

int staircase_steps_dp(int n, vector<int> &dp) { 
    if (n == 0 || n == 1)
        return 1; // only 1 way
    
    if (n == 2)
        return 2; // as we have 2 ways -> 11 or 2

    if (dp[n] != -1)
        return dp[n];
        
    dp[n] = staircase_steps_dp(n - 1, dp) + staircase_steps_dp(n - 2, dp) + staircase_steps_dp(n - 3, dp);
    return dp[n];
}
 
int main()
{
    int n;
    cin >> n;
    cout << staircase_steps(n) << endl;
    vector<int> dp(n + 1, -1); 
    cout << staircase_steps_dp(n, dp) << endl;
    
    return 0;
}