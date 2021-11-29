int orangesRotting(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int countFreshOranges = 0;
        queue<pair<int, int>>q;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 2)  // Put only rotten oranges into queue
                    q.push(make_pair(i, j));
                else if (arr[i][j] == 1) // maintain count of fresh oranges to check if all of them got rotten or not at the end
                    countFreshOranges++;
            }
        }
        
        if (countFreshOranges == 0)
            return 0; // as no time is needed
        
        int numOfLevels = -1; // final answer, Initially we are at level = -1
        vector<vector<int>>directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (q.size() > 0) { // This is for levelwise
            int size = q.size();
            while (size > 0) {
                size--;
                pair<int, int> remaining = q.front();
                q.pop();
                        
                // Check in all 4 directions                
                for (int i = 0; i < 4; i++) {
                    int r_new = remaining.first + directions[i][0];
                    int c_new = remaining.second + directions[i][1];
                    
                    // Check for fresh oranges                     
                    if (r_new >= 0 && c_new >= 0 && r_new < n && c_new < m && arr[r_new][c_new] == 1) {
                        q.push(make_pair(r_new, c_new));
                        arr[r_new][c_new] = 0; // Mark as visited now
                        countFreshOranges--;   // The fresh orange got rotten
                    }
                    
                }
            }
            
            // Move to next level           
            numOfLevels++;
        }
        
        if (countFreshOranges == 0) // all fresh oranges got rotten
            return numOfLevels;
        return -1;
    }