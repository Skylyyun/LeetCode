class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        
        if ( m == 0) return 0;
        //if  (grid == NULL) return 0;

        int n = grid[0].size();

        //开四个数组
        vector<vector<int>> up   (m, vector<int>(n));
        vector<vector<int>> down (m, vector<int>(n));
        vector<vector<int>> left (m, vector<int>(n));
        vector<vector<int>> right(m, vector<int>(n));

        int i = 0, j = 0, res = 0, t = 0;
        for (i = 0; i < m; i ++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == 'W') {
                    up  [i][j] = 0;
                    left[i][j] = 0;
                    continue;
                }

                left[i][j] = up[i][j] = grid[i][j] == 'E'? 1 : 0;
                if (i > 0) {
                    up[i][j] += up[i - 1][j];
                }
                if(j > 0)
                    left[i][j] += left[i][j -1];
            }
        }

        for (i = m -1; i >= 0; i --) {
            for (j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 'W') {
                    up[i][j] = 0;
                    right[i][j] = 0;
                    continue;
                }

                right[i][j] = down[i][j] = (grid[i][j] == 'E'? 1 : 0);
                if (i < m -1) {
                    down[i][j] += down[i + 1][j];
                }
                if(j < n -1)
                    right[i][j] += right[i][j + 1];
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j ++) {
                //开始考虑了三种情况，现在只考虑空地
                if (grid[i][j] == '0'){
                    t = up[i][j] + down[i][j] + left[i][j] + right[i][j];
                    res = max(res, t);
                }
            }
        }
        return res;
    }
};