class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int m = nums.size();
        if(m == 0) return 0;

        vector<int> f(nums);

        for (int i = 0; i < m; i++) {
            //case 1;
            f[i] = 1;

            //case 2;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[j]+1, f[i]);
                }
            }
        }

        return *max_element(f.begin(), f.end());
    }
};