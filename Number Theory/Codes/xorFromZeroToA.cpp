#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

// XOR from 0, 1, 2, ..., a
int findXorFromZeroToA(int a) {
    int xor_zero_to_a = 0;
    if (a % 4 == 0) xor_zero_to_a = a;
    if (a % 4 == 1) xor_zero_to_a = 1;
    if (a % 4 == 2) xor_zero_to_a = a + 1;
    if (a % 4 == 3) xor_zero_to_a = 0;
    return xor_zero_to_a;

}
 
int main()
{
    fast_cin();
    int n;
    cin >> n;
    cout << findXorFromZeroToA(n) << endl;
    return 0;
}