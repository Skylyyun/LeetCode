class Solution {
public:
    bool canJump(vector<int>& nums) {
        //开数组 f[i]表示能否到达i点
        int length = nums.size();
        bool f[length];

        //初始条件
        f[0] = true;

        //状态转移  计算顺序： 还是从左到右
        //f[j] = OR(0 =< i < j) (f[i] && j-i <= ai)
        // previos stone i
        // last jump from i to j
        int i, j;
        for (j = 1; j < length; j++) {
            f[j] = false;
            for (i = 0; i < j; i++) {
                if(f[i] && (j - i <= nums[i])) {
                    f[j] = true;
                    break;
                }
            }
            if(!f[j])
                return false;
        } 
        return f[length - 1];
    }
};