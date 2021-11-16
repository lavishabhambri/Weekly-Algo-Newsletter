#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int log_a_to_base_b(int a, int b) {
    return log(a) / log(b);
} 

int numberOfDigitsInRepresentationInBaseB(int number, int base) {
    int value = log_a_to_base_b(number, base); // log() - gives log w.r.t  base = e
    return value + 1;
}
 
int main()
{
    fast_cin();
    int number, base;
    cin >> number >> base;
    cout << numberOfDigitsInRepresentationInBaseB(number, base) << endl;
    return 0;
}