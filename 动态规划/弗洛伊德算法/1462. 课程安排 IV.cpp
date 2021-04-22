//暴力打表法
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> edges;
        vector<vector<int>> newedges;
        vector<bool> result;
        edges.resize(n);
        newedges.resize(n);
        result.resize(queries.size());

        //还是得先有第一层
        for (auto pre: prerequisites) {
            edges[pre[0]].push_back(pre[1]);
        }

        //使用队列
        queue<int> q;

        //保存了所有的映射
        for (int i = 0; i < n; i++) {
            q.push(i);
            while (!q.empty()) {
                int e = q.front();
                q.pop();
                for (auto a: edges[e]) {
                    if (find(newedges[i].begin(), newedges[i].end(),a) != newedges[i].end()) {
                        continue;
                    }
                    newedges[i].push_back(a);
                    q.push(a);
                }
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            if (find(newedges[queries[i][0]].begin(), newedges[queries[i][0]].end(),queries[i][1])!= newedges[queries[i][0]].end()) {
                result[i] = true;
            } else {
                result[i] = false;
            }
        }

        return result;
    }
};


//弗洛伊德算法,非常地简洁精妙
//使用精妙的弗洛伊德算法
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
         vector<vector<bool>> dp(n, vector<bool>(n)); //初始化值都为0，所以为false.
         vector<bool> result;

         for (auto pre : prerequisites) {
             dp[pre[0]][pre[1]] = true;
         }

         for (int k = 0; k < n; k++) {
             for (int i = 0; i < n; i++) {
                 for (int j = 0; j < n; j++) {
                     dp[i][j] = dp[i][j] || (dp[i][k] && dp[k][j]);
                 }
             }
         }

         for (auto que : queries) {
             result.push_back(dp[que[0]][que[1]]);
         }

         return result;
    }
};