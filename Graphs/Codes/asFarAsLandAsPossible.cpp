int maxDistance(vector<vector<int>>& grid) {
        int waterCount = 0;
        int landCount = 0;
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>>q;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push(make_pair(i, j));
                    waterCount++;
                }
                else
                    landCount++;
            }
        }
        
        if (landCount == 0 || waterCount == 0)
            return -1;
        
        int level = -1;
        vector<vector<int>>directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (q.size() > 0) {
            int size = q.size();
            level++;
            while (size-- > 0) {
                pair<int, int>rem = q.front();
                q.pop();
                
                for (int i = 0; i < 4; i++) {
                    int r_new = rem.first + directions[i][0];
                    int c_new = rem.second + directions[i][1];
                    
                    if (r_new < 0 || c_new < 0 || r_new >= n || c_new >= m || grid[r_new][c_new] == 1)          
                        continue;
                    
                    q.push(make_pair(r_new, c_new));
                    grid[r_new][c_new] = 1;
                    
                }
            }
        }
        return level;
    }