#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

// To find a^b
// TC = O(logb)
int power(int a, int b){
    int ans = 1;
    int base = 2;
    while (b > 0) {
        int lastDigit = b & 1;
        if (lastDigit == 1) {
            ans *= a;
        }
        a *= a;
        b = b >> 1; // Discarding the last digit
    }
    return ans;
}
 
int main()
{
    fast_cin();
    int a, b;
    cin >> a >> b;
    cout << power(a, b) << endl;
    return 0;
}