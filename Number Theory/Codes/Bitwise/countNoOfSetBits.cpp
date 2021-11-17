#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
// Approach - 1 
int findSetBits1(int n) {
    int count = 0;
    while (n  > 0) {
        count++;
        n = n & (n - 1);
    }
    return count;
}

int findSetBits2(int n) {
    int count = 0;
    while (n  > 0) {
        count++;
        n = n - (n & (-n));
    }
    return count;
}
 
int main()
{
    fast_cin();
    int n;
    cin >> n;
    cout << findSetBits1(n) << endl;
    cout << findSetBits2(n) << endl;
    return 0;
}