vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(vector<vector<int>> &grid, int row, int col, int color)
{
    grid[row][col] = -color;
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        int r_new = row + direction[i][0];
        int c_new = col + direction[i][1];

        if (r_new < 0 || c_new < 0 || r_new >= grid.size() || c_new >= grid[0].size() || abs(grid[r_new][c_new]) != color)
            continue;

        count++;
        if (grid[r_new][c_new] == color) // means not visited
            dfs(grid, r_new, c_new, color);
    }

    if (count == 4) // no need to change the color
        grid[row][col] = color;
}
vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color)
{
    dfs(grid, row, col, grid[row][col]);

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] < 0)
                grid[i][j] = color;
        }
    }
    return grid;
}