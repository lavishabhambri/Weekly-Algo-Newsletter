#include<bits/stdc++.h>
using namespace std;

int coinChange(int n,int * denoArr, int numD, int ** output)
{
    if(n<0) return 0;
    if(numD==0) return 0;
    if(n==0) return 1;

    if(output[n][numD] > -1) return output[n][numD];

    //include denoArr[0] 
    int first = coinChange( n-denoArr[0], denoArr , numD, output);

    //do not include denoArr[0]
    int second = coinChange( n, denoArr + 1, numD - 1, output);

    //saving in output array
    output[n][numD] = first + second;

    return first + second;
}

int main()
{
    int denoArr[4] = {1,2,3,4};
    int numD = 4;
    int n; cin>>n;
    int **output;
    output = new int*[n+1];
    for(int i=0; i<=n; i++)
    {
        output[i] = new int[numD+1];
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=numD; j++)
        {
            output[i][j] = -1;
        }
    }
    int totalPossible = coinChange(n,denoArr,numD,output);
    cout<<totalPossible<<endl;

    
    for(int i=0; i<=n; i++)
    {
        delete [] output[i];
    }
    delete [] output;
    return 0;
}