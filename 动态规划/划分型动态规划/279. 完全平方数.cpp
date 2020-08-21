class Solution {
public:
    int numSquares(int n) {
        //划分型动态规划：相当于将一个正整数划分成完全平方的各个段
        //转移方程：f[i] = min{f[i - j*j] + 1} || 0 <= j*j <= i*i
        int f[n + 1];

        //初始化
        f[0] = 0;
        for (int i = 1; i <= n; i ++) {
            f[i] = INT32_MAX;
            for (int j = 1; j*j <= i; j++) {
                f[i] = min(f[i], f[i - j*j] + 1);
            } 
        }
        
        return f[n];
    }
};