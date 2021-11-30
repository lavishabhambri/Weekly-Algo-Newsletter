#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

// Stores the longest increasing subsequence ending at the point.
vector<int> LIS(vector<int> arr) {
    int n = arr.size();
    vector<int> output(n, 0); // output[i] stores lis ending at ith index
    output[0] = 1; // 1 element will form a lis of length = 1 including itself

    for (int i = 1; i < n; i++) {
        output[i] = 1;
        int possibleAnswer;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] < arr[j])
                continue;
            
            else {
                possibleAnswer = output[j] + 1;
                if (possibleAnswer > output[i])
                    output[i] = possibleAnswer;
            }
        }
    }
    return output;
}

// Stores the longest decreasing subsequence starting from that point
vector<int> LDS(vector<int> arr) {
    int n = arr.size();
    vector<int> output(n, 0); // output[i] stores lis ending at ith index
    output[0] = 1; // 1 element will form a lis of length = 1 including itself

    for (int i = n - 1; i >= 0; i--) {
        output[i] = 1;
        int possibleAnswer;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j])
                continue;
            
            else {
                possibleAnswer = output[j] + 1;
                if (possibleAnswer > output[i])
                    output[i] = possibleAnswer;
            }
        }
    }
    return output;
}


int LBS(vector<int> arr) {
    int lbs = 0;
    vector<int>lis = LIS(arr);
    vector<int>lds = LDS(arr);
    for (int i = 0; i < arr.size(); i++) {
        lbs = max(lbs, lis[i] + lds[i] - 1);
    }
    return lbs;
}
 
int main()
{
    fast_cin();
    int n;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << LBS(arr) << endl;
    return 0;
}