#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

//62 uniquePaths

class Solution {
public:
    int uniquePaths(int m, int n) {
        //开二维数组
        int f[m][n];

        //初始化
        f[0][0] = 1;

        //状态转移 计算顺序：从上到下，从左到右
        int i, j;
        for (i = 0; i < m; i ++ ) {
            for (j = 0; j < n; j++) {
                if( i == 0 || j == 0) {
                    f[i][j] = 1;
                }
                else {
                    f[i][j] = f[i][j - 1] + f[i - 1][j];
                }
            }
        }

        return f[m - 1][n - 1];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);

        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}