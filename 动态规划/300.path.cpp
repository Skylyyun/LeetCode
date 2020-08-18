class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int m = nums.size();
        if(m == 0) return 0;
        int p = 0;
        vector<int> f(nums);
        vector<int> path(nums);  //path: 用来记下每一个的前一个的位置

        for (int i = 0; i < m; i++) {
            //case 1;
            f[i] = 1;
            path[i] = -1;

            //case 2;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[j]+1, f[i]);
                    if (f[i] == f[j] + 1) {
                        path[i] = j;
                    }
                }
            }
        }

        int res = 0;
        for (int k = 0; k < m; k++) {
            res = max(res, f[k]);
            if (res == f[k]) {
                p = k;
            }
        }
        
        vector<int> seq(res);
        for (int i = res -1; i >= 0; i --) {
            seq[i] = nums[p]; //最后一个值
            p = path[i];
        }

        for (int i = 0; i < res; i++) {
            cout << seq[i] << endl;
        }
        return *max_element(f.begin(), f.end());
    }
};