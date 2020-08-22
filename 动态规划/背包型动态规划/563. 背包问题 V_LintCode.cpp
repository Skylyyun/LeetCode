class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
    int backPackV(vector<int> &nums, int target) {
        // write your code here
        //f[i][w]: 用前i个物品有多少种方式可以拼出w
        //核心：第A[i-1]个物品来或者不来
        int n = nums.size();
        vector<vector<int>> f(n+1, vector<int>(target+1));
        
        //初始条件
        f[0][0] = 1;
        for (int i=1;i<=target;i++) {
            f[0][target] = 0;
        }
        
        for(int i=1; i<=n; i++) {
            for (int w=0; w<=target; w++) {
                f[i][w] = 0;
                f[i][w] += f[i-1][w];
                if(w-nums[i-1] >= 0) {  //绝，这里要包括等于0的情况
                    f[i][w] += f[i-1][w-nums[i-1]];
                }
            }
        }
        
        return f[n][target];
    }
};