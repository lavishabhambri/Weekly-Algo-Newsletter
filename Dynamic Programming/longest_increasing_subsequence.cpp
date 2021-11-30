#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

int LIS(vector<int> arr) {
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

    int final_lis = 0;
    for (int i = 0; i < n; i++)
        final_lis = max(final_lis, output[i]);

    return final_lis;
}
 
int main()
{
    fast_cin();
    int n;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << LIS(arr) << endl;
    return 0;
}