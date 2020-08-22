class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    //和算钱的那个问题相同
    //f[i] = f[i-nums[0] +....+f[i-nums[n-1]];
    int backPackIV(vector<int> &nums, int target) {
        int n = nums.size();
        
        vector<int> f(target+1);
        f[0] = 1;
        
        for (int i = 1; i<n; i++) {
            f[i] = 0;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = nums[i]; j <= target; j++) {
                f[j] += f[j-nums[i]];
            }
        }
        
        return f[target];
    }
};

//不同顺序算一种