class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> f(num + 1);
        f[0] = 0;
        for (int i = 1; i < num + 1; i ++) {
            f[i] = (i&1) + f[i >> 1];
        }
        return f;

    }
};