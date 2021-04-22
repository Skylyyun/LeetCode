class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int length = s.length();
        if (length == 0) return 0;
        if (length == 1) return 1;

        vector<vector<int>> f(length, vector<int>(length));
        int i, j, len;
        
        //len 1
        for (i = 0; i < length; i++) {
            f[i][i] = 1;
        }

        //len 2
        for (i = 0; i < length-1; i++) {
            f[i][i+1] = s[i] == s[i+1] ? 2: 1;
        }

        //0 1 2 3 ... n-3  n-1
        for (len = 3; len <= length; len++) {
            for (i = 0; i <= length-len; i++) {
                j = i + len -1;
                // [i, j]
                //三种情况： f[i][j] = f[i+1][j] + f[i][j-1] + (f[i+1]f[j-1]+2)
                f[i][j] = max(f[i+1][j], f[i][j-1]);
                if (s[i] == s[j]) {
                    f[i][j] = max(f[i][j], f[i+1][j-1] +2);
                }
            }
        }
        return f[0][length-1];

    }
};