class Solution {
public:
    int cal(vector<int>& nums) {
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

    int rob(vector<int>& nums) {
        //分为不偷n-1和不偷n
        int m = nums.size();
        if (m == 0) return 0;
        if (m == 1) return nums[0];
        vector<int> A(m -1);
        
        int res = 0;

        //不要N-1
        for (int i = 0; i < m - 1; i ++) {
            A[i] = nums[i];
        }
        res = max(res, cal(A));

        //不要0
        for (int i = 0; i < m - 1; i ++) {
            A[i] = nums[i + 1];
        }
        res = max(res, cal(A));

        return res;
    }
};