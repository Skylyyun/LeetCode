class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        if (m == 0) return 0;

        //序列型动规，开数组，分成5个阶段
        int f[m + 1][5 + 1];
        int i, j;

        //初始化
        f[0][1] = 0;
        for (j = 2; j <= 5; j++) {
            f[0][j] = INT32_MIN;
        }

        for (i = 1; i <= m; i++) {
            for (j = 1; j <= 5; j+=2) {
                //当处在1，3，5阶段时：f[i][j] = max{f[i-1][j], f[i-1][j-1] + P[i - 1] - P [i -2]}
                f[i][j] = f[i-1][j];
                if (i >= 2 && j > 1 && (f[i-1][j-1] != INT32_MIN)) {
                    f[i][j] = max(f[i][j], f[i -1][j -1] + prices[i-1] - prices[i-2]);
                }
            }

            for (j = 2; j <= 4; j+=2) {
                //当处在2，4阶段时：f[i][j] = max{f[i -1][j] + p[i -1]- p[i -2], f[i-1][j -1]}
                f[i][j] = f[i -1][j-1];
                if(i>=2 && f[i-1][j] != INT32_MIN) {
                    f[i][j] = max(f[i][j], f[i-1][j] + prices[i-1] - prices[i-2]);
                } 
            }
        }
        return max(f[m][1], max(f[m][3], f[m][5]));
    }
};