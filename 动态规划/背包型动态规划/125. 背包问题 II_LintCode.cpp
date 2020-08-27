class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int n = A.size();
        if (m == 0 || n == 0) return 0;
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        int i, w;
        
        //初始化
        f[0][0] = 0;
        for (i = 1; i <= m; i++) {
            f[0][i] = -1;
        }
        
        for (i = 1; i<= n; i ++) {
            for (w = 0; w <= m; w++) {
                f[i][w] = f[i - 1][w];
                //w - A[i-1] 可以等于0，这样才能加到初始值
                if (w - A[i-1] >= 0 && f[i-1][w - A[i-1]] != -1) {
                    f[i][w] = max(f[i][w], f[i-1][w - A[i-1]] + V[i-1]);
                }
            }
        }
        
        return *max_element(f[n].begin(), f[n].end());
    }
};