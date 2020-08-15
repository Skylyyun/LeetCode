class Solution {
public:
    int climbStairs(int n) {
        //开数组, F表示到第i级台阶的方法数
        int F[n];

        if(n == 1 ) {
            return 1;
        }

        if(n == 2) {
            return 2;
        }

        if(n > 2) {
            //初始化
            F[0] = 1;
            F[1] = 2; 

            //状态转换： F[i] = F[i - 1] + F[i - 2];
            for (int i = 2; i < n; i ++) {
                F[i] = F[i - 1] + F[i - 2];
            }
        }

        return F[n - 1];
    }
};