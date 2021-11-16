#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
// Finding the & with 0 -> 0
// Finding the & with 1 -> that digit only
// If n & 1 == 1 -> odd
// else even
void checkEvenOrOdd(int n) {
    if (n & 1)
        cout << "Odd";
    else
        cout << "Even";
    cout << endl;
}
 
int main()
{
    fast_cin();
    int n;
    cin >> n;
    checkEvenOrOdd(n);
    return 0;
}