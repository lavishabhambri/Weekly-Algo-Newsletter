#include <bits/stdc++.h>  
#include <fstream>
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
// We will create an array & store the pair (arr[i], i) into that. Then we will sort the array
// Then we will iterate over this array & check if any element is at the same position before & after sorting, means element needs 0 swaps. So, continue
// For rest of the unvisited elements we will find the cycle length formed and the swaps will be = cycleLength - 1 as to swap n elements we need only n-1 moves.
// So for all the cycles formed add the moves into answer.
// To detect the cycle we will be using a visited array
int findMinSwaps(vector<int>arr) {
    int n = arr.size();
    vector<pair<int, int>>arr_pair(n);
    for (int i = 0; i < n; i++) {
        arr_pair[i] = make_pair(arr[i], i);
    }

    // Sort the arr_pair
    sort(arr_pair.begin(), arr_pair.end());

    // Make a visited vector
    vector<bool>visited(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // If element is already visited or the element is at its right position, then continue as no swap will be there
        if (visited[i] || arr_pair[i].second == i) {
            continue;
        }

        int cycleLength = 0;
        int j = i;
        // As soon as we get an element that is already visited, it means we got a cycle
        while (visited[j] == false) {
            visited[j] = true;
            cycleLength++;
            j = arr_pair[j].second;
        }
        ans += (cycleLength - 1);
    }
    return ans;
}
 
int main()
{
    fast_cin();
    int n;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << findMinSwaps(arr) << endl;
    return 0;
}