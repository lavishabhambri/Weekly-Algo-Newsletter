#include <bits/stdc++.h>  
#include <fstream>
#define INT_SIZE 32 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

int findNthMagicNumber(int n){
    int magicNumber = 0; // getting the rightMost digit
    int power = 1;
    int base = 5;
    while (n != 0) {
        int lastDigit = (n & 1);
        magicNumber += (lastDigit * base);
        base *= 5;
        power++;
        n = n >> 1;  // discarding the rightMost digit
    }
    return magicNumber;
}
 
int main()
{
    fast_cin();
    int n;
    cin >> n;
    cout << findNthMagicNumber(n) << endl;
    return 0;
}