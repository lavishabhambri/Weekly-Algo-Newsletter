vector<vector<int>> updateMatrix(vector<vector<int>>&v) {
    int n = v.size();
    int m = v[0].size();

    queue<pair<int, int>>q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0) { // add in queue
                q.push(make_pair(i, j));
            }else // insert answer as -1
                v[i][j] = -1;
        }
    }

    while (q.size() > 0) {
        pair<int, int>rem = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int i_new = rem.first + direction[k][0];
            int j_new = rem.second + direction[k][1];

            if (i_new >= 0 && j_new >= 0 && i_new < n && j_new < m) {
                if (v[i_new][j_new] < 0) { // means its unvisited
                    q.push(make_pair(i_new, j_new));
                    v[i_new][j_new] = v[rem.first][rem.second] + 1;
                }
            }
        }
    }
    return v;
}