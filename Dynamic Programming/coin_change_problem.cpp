#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

int find_coin_change_ways(vector<int> denominations, int totalChange, int start) {
    // Base case - 1
    if (totalChange == 0) // As this can also become negative
        return 1; // Don't give anything is 1 way
    
    if (totalChange < 0)
        return 0;

    if (denominations.size() <= start)
        return 0; // here we can't give anything as we don't have any denominations

    int including_ith_denomination = find_coin_change_ways(denominations, totalChange - denominations[start], start);
    int excluding_ith_denomination = find_coin_change_ways(denominations, totalChange, start + 1);

    return including_ith_denomination + excluding_ith_denomination;
}
 
int find_coin_change_ways_dp(vector<int> denominations, int totalChange, int start, vector<vector<int>>& dp) {
    // Base case - 1
    if (totalChange == 0) // As this can also become negative
        return 1; // Don't give anything is 1 way
    
    if (totalChange < 0)
        return 0;

    if (denominations.size() <= start)
        return 0; // here we can't give anything as we don't have any denominations
    
    if (dp[start][totalChange] != -1)
        return dp[start][totalChange];

    int including_ith_denomination = find_coin_change_ways_dp(denominations, totalChange - denominations[start], start, dp);
    int excluding_ith_denomination = find_coin_change_ways_dp(denominations, totalChange, start + 1, dp);

    dp[start][totalChange] = including_ith_denomination + excluding_ith_denomination;
    return dp[start][totalChange];
}


int main()
{
    fast_cin();
    int n;
    cin >> n;
    vector<int> denominations(n);
    for (int i = 0; i < n; i++)
        cin >> denominations[i];
    int totalChange;
    cin >> totalChange;
    
    cout << "Recursive : " << find_coin_change_ways(denominations, totalChange, 0) << endl;

    // 2D DP array
    vector<vector<int>>dp(n + 1, vector<int>(totalChange + 1, -1));
    cout << "DP : " << find_coin_change_ways_dp(denominations, totalChange, 0, dp) << endl;
    return 0;
}