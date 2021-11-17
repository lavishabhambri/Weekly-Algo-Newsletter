#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

bool canMeasureWater(int a, int b, int c) {
    if(c>a+b)return false;
    for(int i=1;i<=max(a,max(b,c));i++)
    {
        long long int f= (long long int)a*(long long int)i;
        long long  int z= abs((long long int)c-f);
        if(z%b==0)
            return true;
        
    }
    return false;
    
}
 
int main()
{
    fast_cin();
    int a,b,c;
    cin >> a >>b >> c;
    cout << canMeasureWater(a, b, c) << endl;
    return 0;
}