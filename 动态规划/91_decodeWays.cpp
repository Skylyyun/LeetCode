class Solution {
public:
    int numDecodings(string s) {
        int strLength = s.length();
        if(strLength == 0) {
            return 0;
        }

        //开数组, 前i个有多少钟方法
        int f[strLength + 1];
        //初始化
        f[0] = 1;

        for (int i = 1; i <= strLength; i++) {
            //数组元素记得初始化
            f[i] = 0;
            if(s[i - 1] >= '1' && s[i - 1] <= '9') {
                f[i] += f[i - 1];
            }

            //只有i > 1 的时候才有两位数的情况
            if(i > 1) {
                int j = 10 * (s[i - 2] - '0') + (s[i -1] - '0');
                if(j >= 10 && j <= 26) {
                    f[i] += f[i -2];
                }
            }
        }
        return f[strLength];        
    }
};