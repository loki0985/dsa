class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> dp(n, 0);

        // Starting point
        dp[0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // If obstacle, no path possible
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                }
                else {
                    // Add paths from left cell
                    if (j > 0)
                        dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n - 1];
    }
};