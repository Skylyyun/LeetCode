//滑动窗口法
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //滑动窗口
        if (s.size() == 0) return 0;
        unordered_set<char> lookup;
        int left = 0;
        int maxStr = 0;

        for (auto i = 0; i < s.size(); i++) {
            while(lookup.find(s[i]) != lookup.end()) {
                lookup.erase(s[left]);
                left++;
            }
            lookup.insert(s[i]);
            maxStr = max(maxStr, i-left+1);
        }
        return maxStr;
    }
};


//直接记录出现两个重复字符之间的最大距离
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //滑动窗口 + hashmap
        //参考：https://www.cnblogs.com/grandyang/p/4480780.html
        int left = -1;
        int res = 0;
        vector<int> lookup(256, -1);

        for (int i = 0; i < s.size(); i++) {
            //没有出现过的话，lookup[s[i]] 就是-1；
            left = max(left, lookup[s[i]]);
            lookup[s[i]] = i;
            res = max(res, i-left);
        }
        return res;
    }
};

