//博弈型动态规划：记住必胜态和必败态

class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here
        //根据课上的图可知：每次都替换先手
        //f[i] = !f[i-1] or !f[i-2];
        
        if (n == 0) return 0;
        
        int f[n+1]; //记录面对第i个石子的状态
        f[0] = 0;
        f[1] = f[2] = true;
        for (int i = 3; i <= n; i++) {
            if(f[i-1] == false || f[i-2] == false) {
                f[i] = true;
            }
            else {
                f[i] = false;
            }
        }
        
        return f[n];
        
    }
};