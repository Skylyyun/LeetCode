class Solution {
public:
    int rob(vector<int>& nums) {
        //f[i] = max{f[i - 1], f[i - 2] + nums[i -1]} 
        int m = nums.size();
        if (m == 0) return 0;
        vector<int> f(m + 1);

        //使用old和now

        int old = 0;
        int now =  nums[0];
        int t;
        for (int i = 2; i <= m; i++) {
            t = max(now, old + nums[i - 1]);
            old = now;
            now = t;
            
        }
        return now;
    }
};