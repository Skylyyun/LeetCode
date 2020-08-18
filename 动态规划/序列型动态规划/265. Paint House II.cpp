class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int m = costs.size();
        if (m == 0) return 0;
        int n = costs[0].size();
        vector<vector<int>> f(m + 1, vector<int>(n));
        int i, j;

        //min1最小值， min2次小值
        int min1, min2;
        int d1 = 0, d2 = 0;

        //初始值  可以把1也赋值了
        for (j = 0; j < n; j++) {
            f[0][j] = 0;
            f[1][j] = costs[0][j];
        }

        for(i = 2; i <= m; i++) {
            min1 = INT32_MAX;
            min2 = INT32_MAX;
            for (j = 0; j < n; j++) {
                if(f[i -1][j] < min1) {
                    min2 = min1;
                    d2 = d1;
                    min1 = f[i- 1][j];
                    d1 = j;
                }
                else {
                    if (f[i -1][j] < min2) {
                        min2 = f[i - 1][j];
                        d2 = j;
                    }
                }
            }

            for (j = 0; j < n; j ++) {
                f[i][j] = costs[i - 1][j];
                if (j != d1) {
                    f[i][j] += min1;
                }
                else {
                    f[i][j] += min2;
                }
            }

        }

        return *min_element(f[m].begin(), f[m].end());

    }
};