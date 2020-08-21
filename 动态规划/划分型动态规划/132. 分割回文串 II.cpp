class Solution {
public:
    vector<vector<int>> isPalin(string s) {
        //两种情况：奇数回文串和偶数回文串
        int n = s.length();
        int number = 0;
        int i, j ; //       
        vector<vector<int>> f(n,vector<int>(n));

        for (i = 0; i < n;i++) 
            for (j = 0; j < n; j++)
                f[i][j] = false;
        
        //为奇数回文串，中间的字符为对称轴
        for (int c = 0; c < n; c++) {
            i = c;
            j = c;
            while( i >= 0 && j < n &&(s[i] == s[j])) {  //j从0开始包括了单子符的情况
                f[i][j] = true;
                i--;
                j++;
            }
        }

        //为偶数回文串，中间线为对称轴
        for (int c = 0; c < n-1; c++) {
            i = c;
            j = c+1;
            while( i >= 0 && j < n && (s[i] == s[j])) {
                f[i][j] = true;
                i--;
                j++;
            }
        }

        return f;
    }  
    
    
    int minCut(string s) {
        int n = s.length();
        if(n == 0) return 0;
        vector<vector<int>> f(n, vector<int>(n));

        f = isPalin(s);
        vector<int> mincut(n+1);

        mincut[0] = 0;

        for (int i = 1; i <= n; i++) {
            mincut[i] = INT32_MAX;
            for (int j = 0; j <= i-1; j++){
                if(f[j][i-1] && mincut[j] != INT32_MAX){
                    mincut[i] = min(mincut[i], mincut[j]+1);
                }
            }
        }
        return mincut[n]-1;
    }
};