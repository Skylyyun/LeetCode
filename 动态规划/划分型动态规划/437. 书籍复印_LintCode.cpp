class Solution {
public:
    vector<int> sum(vector<int> &pages) {
        vector<int> partSum(pages);
        partSum[0] = pages[0];
        int n = pages.size();
        for (int i=1; i<n; i++) {
            partSum[i] = partSum[i-1] + pages[i];
        }
        
        return partSum;
    }
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        //划分型动态规划：f[k][i]: 表示前k个人抄万i本书所需要的最短时间
        //f[k][i] = min(0=<j<=i) {max{f[k-1][j],pages[j]+.....+pages[i-1]}
        
        int n = pages.size();
        if(n==0) return 0;
        if (k>n) k=n;
        vector<vector<int>> f(k+1, vector<int>(n+1));
        int i,j,m;
        vector<int> partSum = sum(pages);
        
        f[0][0] = 0;
        for (i=1; i<=n; i++) {
            f[0][i] = INT32_MAX;
        }
        
        for (m=1; m<=k; m++) {
            for (i=0; i<=n; i++) { 
                f[m][i] = INT32_MAX;
                for (j=0; j<=i; j++) {
                    f[m][i] = min(f[m][i], max(f[m-1][j], partSum[i-1]-partSum[j-1]));
                }
            }
        }
        
        return f[k][n];
        
    }
};