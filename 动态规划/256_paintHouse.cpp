class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        //序列型动态规划
        //初始判断
        int m = costs.size();
        if (m  == 0) return 0;

        //开数组， f[i][j]: 记录前n个房子的最小花费，j分别表示三种颜色
        vector<vector<int>> f(m + 1, vector<int>(3));
        //初始情况：前0栋房子
        f[0][0] = f[0][1] = f[0][2] = 0;
        //前i栋房子
        for (int i = 1; i <= m; i++) {
            //第i-1栋房子的颜色： j
            for (int j = 0; j < 3; j++) {
                f[i][j] = INT32_MAX;
                //第i-2栋房子的颜色：k
                for (int k = 0; k < 3; k++) {   
                    if(j != k)
                        f[i][j] = min(f[i][j], f[i -1][k] + costs[i - 1][j]);
                }
            }
        }
        return min(f[m][0], min(f[m][1], f[m][2]));
    }
};