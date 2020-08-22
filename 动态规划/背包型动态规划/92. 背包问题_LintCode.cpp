class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        // 背包问题要记得将重量m放入数组中
        int n = A.size();
        if (n == 0 || m == 0) {
            return 0;
        }
        int i,w, target;
        
        //backPack[i][w]:计算前i个物品是否可以达到重量w。
        bool backPack[n+1][m+1];
        //初始化第一行
        backPack[0][0] = true;
        for (i=1; i<=m; i++) {
            backPack[0][i] = false;
        }
        
        for (i=1; i<=n; i++) {
            for (w=0; w<=m; w++) {
                backPack[i][w] = false;
                if(backPack[i-1][w]) {
                    backPack[i][w] = true;
                }
                if(w-A[i-1]>=0 && backPack[i-1][w-A[i-1]]) {
                    backPack[i][w] = true;
                }
            }
        }
        for (i=1;i<=m;i++) {
            if(backPack[n][i]) {
                target = i;
            }
        }
        
        return target;
    }
};