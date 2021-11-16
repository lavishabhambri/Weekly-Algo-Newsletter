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

// Range XOR from l to r = (XOR from 0, 1, 2, ..., l) ^ (XOR from 0, 1, 2, ..., r)
int findXOR_betweenLAndR(int l, int r) {
    int xor_zero_to_before_l = findXorFromZeroToA(l-1);
    int xor_zero_to_r = findXorFromZeroToA(r);
    return xor_zero_to_before_l ^ xor_zero_to_r;
}
 
int main()
{
    fast_cin();
    int l, r;
    cin >> l >> r;
    cout << findXOR_betweenLAndR(l, r) << endl;
    return 0;
}