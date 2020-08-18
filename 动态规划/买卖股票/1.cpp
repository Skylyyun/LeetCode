class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //核心： 时刻保存到目前为止的最小值
        int m = prices.size();
        if(m == 0) return 0;

        int res = 0;
        int minValue = prices[0];
        for (int i = 1; i < m; i ++) {
            res = max(res, prices[i] - minValue);
            minValue = min(minValue, prices[i]);
        }

        return res;

    }
};