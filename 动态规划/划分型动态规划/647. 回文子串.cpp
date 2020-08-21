class Solution {
public:
    int countSubstrings(string s) {
        //两种情况：奇数回文串和偶数回文串
        int n = s.length();
        if (n == 0) return 0;
        int number = 0;
        int j = 0; //双指针
        
        //为奇数回文串，中间的字符为对称轴
        for (int i = 0; i < n; i++) {
            j = 0;  //注意每次要重置j=0
            while( i-j >= 0 && i+j < n &&(s[i-j] == s[i+j])) {  //j从0开始包括了单子符的情况
                number ++;
                j++;
            }
        }

        //为偶数回文串，中间线为对称轴
        for (int i = 0; i < n-1; i++) {
            j = i+1;
            while( i >= 0 && j < n && (s[i] == s[j])) {
                number ++;
                i--;
                j++;
            }
        }

        return number;
    }
};