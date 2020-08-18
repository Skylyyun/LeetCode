class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int m = envelopes.size();
        if (m == 0) return 0;
        //根据长和宽排序 envelopes[i][0]: width
        vector<int> f(m);

        //要用小于号不能用减号
        sort(envelopes.begin(), envelopes.end(),[](const vector<int>& v1,const vector<int>& v2) {
            if(v1[0] == v2[0])
                return v1[1] < v2[1];
            else
                return v1[0] < v2[0];
        }); 

        for(int i = 0; i < m; i++) {
            //case 1
            f[i] = 1;

            //case 2
            for (int j = 0; j < i; j++) {
                if (envelopes[j][0] < envelopes[i][0] && (envelopes[j][1] < envelopes[i][1])) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        
        return *max_element(f.begin(), f.end());
    }
};