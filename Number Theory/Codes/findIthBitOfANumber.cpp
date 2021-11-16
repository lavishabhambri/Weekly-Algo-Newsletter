#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

int findIthBitOfANumber(int n) {
    // In mask the all digits except the ith bit with 0 and the ith bit with 1 to get ith bit
    // On doing & we will get ith bit
    int mask = (1 << (n - 1)); // 0000100 -> to find 3rd bit
    return n & mask;
}

int setTheIthBit(int n) {
    // Means making ith bit = 1
    // Means in mask we want all the digits except the ith digit to be same as earlier and ith digit should be 1
    // On doing the or of the mask with no, we set the bit to 1
    int mask = (1 << (n - 1));
    n = n | mask;
    return n;
}

int resetTheIthBit(int n) {
    // Means make the ith bit = 0
    // Means in the mask we want all the digits to be same as earlier, except the ith digit to be = 0
    // Hence And the no. with 111011 (if we want to reset 3rd bit)
    // 111011 = complement of 000100
    int mask = (1 << (n - 1));
    int complement_mask = !mask;
    n = n & complement_mask;
    return n;
}

int findPositionOfRightMostSetBit(int n) {
    return n & (-n); // Here mask is -ve of given no.
}
 
int main()
{
    fast_cin();
    int n;
    cin >> n;
    return 0;
}