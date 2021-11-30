#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

int min_cost(vector<vector<int>>input, int start_i, int start_j, int end_i, int end_j) {
    if (start_i == end_i && start_j == end_j) // Means start == end
        return input[start_i][start_j];

    // Check for boundary cases, i.e we are returning infinite cost from the right & bottom boundary
    if (start_i > end_i || start_j > end_j) 
        return INT_MAX;
    
    int cost1 = min_cost(input, start_i + 1, start_j, end_i, end_j);     // Right
    int cost2 = min_cost(input, start_i + 1, start_j + 1, end_i, end_j); // Diagonal
    int cost3 = min_cost(input, start_i, start_j + 1, end_i, end_j);     // Down
    return input[start_i][start_j] + min(cost1, min(cost2, cost3)); 
}


int min_cost_dp(vector<vector<int>>input, int start_i, int start_j, int end_i, int end_j, vector<vector<int>>&dp) {
    if (start_i == end_i && start_j == end_j) // Means start == end
        return input[start_i][start_j];

    // Check for boundary cases, i.e we are returning infinite cost from the right & bottom boundary
    if (start_i > end_i || start_j > end_j) 
        return INT_MAX;

    if (dp[start_i][start_j] != -1)
        return dp[start_i][start_j];
    
    int cost1 = min_cost_dp(input, start_i + 1, start_j, end_i, end_j, dp);     // Right
    int cost2 = min_cost_dp(input, start_i + 1, start_j + 1, end_i, end_j, dp); // Diagonal
    int cost3 = min_cost_dp(input, start_i, start_j + 1, end_i, end_j, dp);     // Down
    dp[start_i][start_j] = input[start_i][start_j] + min(cost1, min(cost2, cost3));
    return dp[start_i][start_j]; 
}


int min_cost_iterative(vector<vector<int>>input) {
    int m = input.size();
    int n = input[0].size();

    // In this dp[i][j] -> stores the minimum distance from (i, j) to (m - 1, n - 1).
    vector<vector<int>> dp(m, vector<int>(n));

    dp[m - 1][n - 1] = input[m - 1][n - 1];

    // Filling the last column
    for (int j = n - 2; j >= 0; j--) 
        dp[m - 1][j] = dp[m - 1][j + 1] + input[m - 1][j];

    // Filling the row
    for (int i = m - 2; i >= 0; i--) 
        dp[i][n - 1] = dp[i + 1][n - 1] + input[i][n - 1];

    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            dp[i][j] = input[i][j] + min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1]));
        }
    }
    return dp[0][0];
}
 
int main()
{
    fast_cin();
    int n, m;
    cin >> n >> m;
    vector<vector<int>>input(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> input[i][j];
    }

    cout << "Recursive : " << min_cost(input, 0, 0, n - 1, m - 1) << endl;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << "DP : " << min_cost_dp(input, 0, 0, n - 1, m - 1, dp) << endl;

    cout << "Iterative : " << min_cost_iterative(input) << endl;
    return 0;
}