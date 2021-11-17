// C++ program to check whether a number
// is prime or not using recursion
#include <iostream>
using namespace std;

// function check whether a number
// is prime or not
bool isPrime(int n)
{
	static int i = 2;

	// corner cases
	if (n == 0 || n == 1) {
		return false;
	}

	// Checking Prime
	if (n == i)
		return true;

	// base cases
	if (n % i == 0) {
		return false;
	}
	i++;
	return isPrime(n);
}

// Driver Code
int main()
{

	isPrime(35) ? cout << " true\n" : cout << " false\n";
	return 0;
}
