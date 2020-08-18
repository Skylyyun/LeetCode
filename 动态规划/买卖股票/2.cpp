class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        if (m == 0 || m == 1) return 0;

        int res = 0;
        for (int i = 1; i < m; i++) {
            if (prices[i] > prices[i - 1]) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }
};