#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
// Let we take the input as array
int num_codes(vector<int> arr, int n) {
    // When size == 1 then only 1 code is possible
    if (n == 1)
        return 1;

    if (n == 0) 
        return 1;  // empty string is the only alpha code

    // Lets call recursion on starting part & our work will be on the ending part
    int output = num_codes(arr, n - 1);

    // Check for the other call - call on the second left
    if (arr[n-2]*10 + arr[n-1] <= 26)
        output += num_codes(arr, n - 2); // size > 1

    return output;
}


// Let we take the input as array
int num_codes_dp(vector<int> arr, int n, vector<int> dp) {
    // If value is already stored
    if (dp[n] > 0)
        return dp[n];
    // When size == 1 then only 1 code is possible
    if (n == 1)
        return 1;

    if (n == 0) 
        return 1;  // empty string is the only alpha code

    // Lets call recursion on starting part & our work will be on the ending part
    int output = num_codes(arr, n - 1);

    // Check for the other call - call on the second left
    if (arr[n-2]*10 + arr[n-1] <= 26)
        output += num_codes(arr, n - 2); // size > 1

    dp[n] = output;
    return output;
}


int num_codes_iterative(vector<int> arr, int n) {
    int *output = new int[n + 1];
    output[0] = 1; // empty string 
    output[1] = 1; // that digit only

    for (int i = 2; i <= n; i++) {
        output[i] = output[i - 1];

        if (arr[i - 2] * 10 + arr[i - 1] <= 26)  // if last digits <= 26, then add output[i - 2] as well.
            output[i] += output[i - 2];
    }
    return output[n];
}


int main()
{
    fast_cin();
    vector<int> arr(100000000);
    string s;
    cin >> s;
    int i = 0;
    while (s[i] != '\0') {
        arr[i] = s[i] - '0';
        i++;
    }
    vector<int> dp(100000000 + 1, 0);
    cout << "Recursive : " << num_codes(arr, i) << endl;
    cout << "Dp : " << num_codes_dp(arr, i, dp) << endl;
    cout << "Iterative : " << num_codes_iterative(arr, i) << endl;
    
    return 0;
}