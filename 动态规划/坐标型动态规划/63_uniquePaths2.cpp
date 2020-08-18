class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (m == 0) return 0;
        
        vector<vector<int>> dp(obstacleGrid);
        //遍历容器
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //障碍物, 一票否决，如果是1就直接置0
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                //初始情况
                if (i == 0 && j == 0) {    
                    dp[i][j] = 1;
                    continue;
                }

                //考虑其他情况，首先都赋值为0，囊括了i=0和j=0 的情况， dp[0][2] = 0时， dp[0][3]也只能等于0
                dp[i][j] = 0;
                if(i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n -1];
    }
};