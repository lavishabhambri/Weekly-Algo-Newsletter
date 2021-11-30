#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
int min_health(vector<vector<int>> input, int start_i, int start_j, int end_i, int end_j) {
    if (start_i == end_i && start_j == end_j) {
        if (input[start_i][start_j] <= 0)
            return abs(input[start_i][start_j]) + 1;
        else
            return 1;
    }
    
    if (start_i > end_i || start_j > end_j)
        return INT_MAX;
    
    int cost1 = min_health(input, start_i + 1, start_j, end_i, end_j) - input[start_i][start_j];
    int cost2 = min_health(input, start_i, start_j + 1, end_i, end_j) - input[start_i][start_j];
    int min_health_needed = min(cost1, cost2);
    if (min_health_needed <= 0)
        return 1;
    return min_health_needed;
}

int strength(vector<vector<int>> arr, int r, int c)
{
    int **temp = new int *[r];
    for (int i = 0; i < r; i++) {
        temp[i] = new int[c]();
    }
    temp[r - 1][c - 1] = 1;
    temp[r - 2][c - 1] = 1;
    temp[r - 1][c - 2] = 1;

    for (int i = c - 3; i >= 0; i--) {
        if (arr[r - 1][i + 1] < 0)
            temp[r - 1][i] = temp[r - 1][i + 1] - arr[r - 1][i + 1];
        else
            temp[r - 1][i] = max(1, temp[r - 1][i + 1] - arr[r - 1][i + 1]);
    }

    for (int i = r - 3; i >= 0; i--) {
        if (arr[i + 1][c - 1] < 0)
            temp[i][c - 1] = temp[i + 1][c - 1] - arr[i + 1][c - 1];
        else
            temp[i][c - 1] = max(1, temp[i + 1][c - 1] - arr[i + 1][c - 1]);
    }


    for (int i = r - 2; i >= 0; i--) {
        for (int j = c - 2; j >= 0; j--) {
            int down;
            int right;
            if (arr[i + 1][j] < 0)
                down = temp[i + 1][j] - arr[i + 1][j];
            else
                down = max(1, temp[i + 1][j] - arr[i + 1][j]);

            if (arr[i][j + 1] < 0)
                right = temp[i][j + 1] - arr[i][j + 1];
            else
                right = max(1, temp[i][j + 1] - arr[i][j + 1]);

            temp[i][j] = min(down, right);
        }
    }

    int ans = temp[0][0];
    for (int i = 0; i < r; i++) {
        delete[] temp[i];
    }
    delete[] temp;
    return ans;
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

    cout << "Recursive : " << min_health(input, 0, 0, n - 1, m - 1) << endl;

    cout << "DP : " << min_health(input, n, m) << endl;

    return 0;
}