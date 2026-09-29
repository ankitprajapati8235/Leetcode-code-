class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool dfs(int row, int col, int balance, vector<vector<char>>& grid) {
        if(balance < 0) {
            return false;
        }

        int remaining = (m-1-row) + (n-1-col);

        if(balance > remaining) {
            return false;
        }

        if(row == m-1 && col == n-1) {
            return balance == 0;
        }

        if(dp[row][col][balance] != -1) {
            return dp[row][col][balance];
        }

        bool result = false;

        if(row + 1 < m) {
            int newBalance = balance;

            if(grid[row+1][col] == '('){
                newBalance++;
            } else {
                newBalance--;
            }

            result = dfs(row+1, col, newBalance, grid);
        }

        if(!result && col+1 < n) {
            int newBalance = balance;

            if(grid[row][col+1] == '(') {
                newBalance++;
            } else {
                newBalance--;
            }
            result = dfs(row, col+1, newBalance, grid);
        }
        return dp[row][col][balance] = result;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if(grid[0][0] == ')' || grid[m-1][n-1] == '(')
        return false;

        if((m+n-1) % 2 != 0)
        return false;

        dp.assign(m, vector<vector<int>>(n, vector<int>(m+n, -1)));

        return dfs(0, 0, 1, grid);
    }
};