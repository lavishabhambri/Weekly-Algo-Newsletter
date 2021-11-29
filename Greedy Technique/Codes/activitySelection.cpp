#include <bits/stdc++.h>
using namespace std;

// Prints a maximum set of activities that can be done by a single
// person, one at a time.
// n --> Total number of activities
// arr.second --> Contains start time of all activities
// arr.first --> Contains finish time of all activities
void printMaxActivities(vector<pair<int, int>>arr, int n)
{   
    // Sort the given array on basis of finish time
    sort(arr.begin(), arr.end());
    
	int i, j;

	cout <<"Following activities are selected "<< endl;

	// The first activity always gets selected
	i = 0;
	cout <<" "<< i;

	// Consider rest of the activities
	for (j = 1; j < n; j++)
	{
	// If this activity has start time greater than or
	// equal to the finish time of previously selected
	// activity, then select it
	if (arr[j].first >= arr[i].second)
	{
		cout <<" " << j;
		i = j;
	}
	}
}

int main()
{
	int n;
    cin >> n;
    vector<pair<int, int>>arr(n);
    for (int i = 0; i <n; i++) {
        cin >> arr[i].second >> arr[i].first;
    }
	
	printMaxActivities(arr, n);
	return 0;
}
