// A Better (than Naive) Solution to find all divisiors
#include <iostream>
#include <math.h>
using namespace std;

// Function to print the divisors
void printDivisors(int n)
{
	// Note that this loop runs till square root
	for (int i=1; i<=sqrt(n); i++)
	{
		if (n%i == 0)
		{
			// If divisors are equal, print only one
			if (n/i == i)
				cout <<" "<< i;

			else // Otherwise print both
				cout << " "<< i << " " << n/i;
		}
	}
}

/* Driver program to test above function */
int main()
{
	cout <<"The divisors of 100 are: \n";
	printDivisors(100);
	return 0;
}
