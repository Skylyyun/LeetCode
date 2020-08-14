#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

//322 coin change

//动态规划
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 开数组
         int f[amount + 1]; // f 表示最少需要多少硬币配 X 元钱
         int coinNumber = coins.size(); //获得coins的种类

         // 初始化
         f[0] = 0;

         // 状态转移
         int i, j;

         //f[1], f[2], f[3], f[4], f[5], ,,,,, f[n]
         for (i = 1; i <= amount; i ++ ) {
             f[i] = INT32_MAX;

             // last coin coins[j]
             // f[i] = min(f[i - coins[0]] + f[i - coins[1]] + .... + f[i - coins[coinNumber]])
             for (j = 0; j < coinNumber; j ++ ) {
                 // 注意： 等于的时候是可以的， 以及为什么当为最大值的时候要排除，因为在计算机中最大值加一可能会导致越界
                 if (i >= coins[j] && f[i - coins[j]] != INT32_MAX)
                    f[i] = min(f[i - coins[j]] + 1, f[i]);
             }
         }

         if (f[amount] == INT32_MAX)
             f[amount] = -1;

        return f[amount];
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> coins = stringToIntegerVector(line);
        getline(cin, line);
        int amount = stringToInteger(line);

        int ret = Solution().coinChange(coins, amount);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}