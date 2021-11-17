#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

// Sum of each row in pascal's triangle = nC0 + nC1 + nC2 + .... + nCn = 2^n
// If we start from the 0th row then for the nth row, we have n -> n-1
// So, sum of nth row  = 2^(n-1)
int getSumOfNthRow(int n) {
    return (1 << (n - 1)); // 2^(n-1)
}
 
int main()
{
    fast_cin();
    int n;
    cin >> n;
    cout << getSumOfNthRow(n) << endl;
    return 0;
}