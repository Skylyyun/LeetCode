class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 因为有负数的存在，有可能会负负得正，所以还需要维护一个最小值数组
        
        //小括号可以建立一个和nums同样大小的vector
        vector<int> maxF(nums), minF(nums);
        maxF[0] = minF[0] = nums[0]; 
        for (int i = 1; i < nums.size(); i++) {
            //max, min 一次只能比两
            maxF[i] = max(maxF[i - 1] * nums[i], max(minF[i - 1] * nums[i], nums[i]));
            minF[i] = min(maxF[i - 1] * nums[i], min(minF[i - 1] * nums[i], nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};