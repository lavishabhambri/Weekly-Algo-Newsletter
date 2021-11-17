#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

int checkIfPowerOf2(int n){
    if (n == 0) return 0; // false
    return (n & (n - 1)) == 0; // if this is equal to 0, then its a power of 2
}
 
int main()
{
    fast_cin();
    int n;
    cin >> n;
    cout << checkIfPowerOf2(n) << endl;
    return 0;
}