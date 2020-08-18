class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int m = prices.size();
        if ( m == 0) return 0;

        //当K>N/2的时候，等价与第二题
        if(k > m/2) {
            int res = 0;
            for (int i = 1; i < m; i++) {
                if (prices[i] > prices[i - 1]) {
                    res += prices[i] - prices[i - 1];
                }
            }
            return res;
        }

        //当K小于等于N/2时，等价于第三题
        //序列型动规，开数组，分成2k+1个阶段
        int f[2][2*k + 2];
        int i, j;
        int now = 0, old = 0;

        //初始化
        f[now][1] = 0;
        for (j = 2; j <= 2*k + 1; j++) {
            f[now][j] = INT32_MIN;
        }

        for (i = 1; i <= m; i++) {
            //每一行开始的时候记得互换
            old = now;
            now = 1- old;

            for (j = 1; j <= 2*k + 1; j+=2) {
                //当处在1，3，5阶段时：f[i][j] = max{f[i-1][j], f[i-1][j-1] + P[i - 1] - P [i -2]}
                f[now][j] = f[old][j];
                if (i >= 2 && j > 1 && (f[old][j-1] != INT32_MIN)) {
                    f[now][j] = max(f[now][j], f[old][j -1] + prices[i-1] - prices[i-2]);
                }
            }

            for (j = 2; j <= 2*k; j+=2) {
                //当处在2，4阶段时：f[i][j] = max{f[i -1][j] + p[i -1]- p[i -2], f[i-1][j -1]}
                f[now][j] = f[old][j-1];
                if(i>=2 && f[old][j] != INT32_MIN) {
                    f[now][j] = max(f[now][j], f[old][j] + prices[i-1] - prices[i-2]);
                } 
            }
        }

        int res = 0;
        for (i = 1; i <= 2*k +1; i+=2) {
            res = max(res,f[now][i]);
        }
        return res;
 
    }
};