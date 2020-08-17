class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        //坐标型动规， f[i]和下标对应
        vector<int> f(nums);
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            //case 1
            f[i] = 1;

            if (i > 0 && nums[i] > nums[i -1]) {
                f[i] = f[i - 1] + 1;
            }
            res = max(res, f[i]);
        }
        return res;
    }
};