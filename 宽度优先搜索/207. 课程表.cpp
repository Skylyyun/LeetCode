//BFS
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long;

using namespace std;

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    //不一样的地方是它可以不是一个图，有些课程它可以既不是先修课，也不是后修课
    //1. Calulate in degree 2. (0 in degree) node to in queue 3. Uses BFS to abtain the results
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //创建一个拓扑排序后的vector
        vector<int> result;

        //如果没有任何的依赖关系，则返回true
        if (prerequisites.size() == 0) {
            return true;
        }

        unordered_map<int, unordered_set<int>> graph = getGraph(prerequisites);

        //1. count indegree , 计算入度，以完成拓扑排序
        unordered_map<int, int> indegree = getIndegree(prerequisites);

        //2. 获得入度为0的点，以此开始排序
        vector<int> startNodes = getStartNodes(indegree,numCourses);

        //3. bfs , 获得拓扑排序的序列
        result = bfs(indegree, startNodes, graph);

        //最后还要考虑是否遍历了所有得点
        if(result.size() == numCourses) {
            return true;
        }

        return false;
    }

    unordered_map<int, unordered_set<int>> getGraph(vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> graph;
        for (auto n : prerequisites) {
            graph[n[1]].insert(n[0]);
        }
        return graph;
    }

    unordered_map<int, int> getIndegree(vector<vector<int>>& prerequisites) {
        unordered_map<int, int> indegree;
        for (auto n : prerequisites) {
            if (auto it = indegree.find(n[0]) != indegree.end()) {
                indegree[n[0]] += 1;
            }
            else
                indegree[n[0]] = 1;
        }
        return indegree;
    }

    vector<int> getStartNodes(unordered_map<int, int>& indegree,
                              int numCourses) {
        vector<int> startNodes;
        for (auto i = 0; i < numCourses; i++) {
            if (auto it = indegree.find(i) == indegree.end()) {
                startNodes.push_back(i);
            }
        }

        return startNodes;
    }

    vector<int> bfs(unordered_map<int, int>& indegree,
                    vector<int>& startNodes, unordered_map<int, unordered_set<int>> graph) {
        vector<int> result;
        queue<int> Q;

        for (auto n : startNodes) {
            Q.push(n);
            result.push_back(n);
        }

        while(!Q.empty()) {
            auto node = Q.front(); Q.pop();
            for (auto neighbor: graph[node]) {
                //不会重复访问，因为会减到-1
                indegree[neighbor] --;
                if (indegree[neighbor] == 0) {
                    Q.push(neighbor);
                    result.push_back(neighbor);
                }
                else if (indegree[neighbor] <= 0) {
                    result.push_back(neighbor);
                }
            }
        }

        return result;
    }
};

int main(void) {
    int numCourses, course1, course2;
    vector<vector<int>> prerequisites;

    cin >> numCourses;
    while(cin >> course1 ) {
        cin >> course2;
        prerequisites.push_back({course1, course2});
    }

    bool ret = Solution().canFinish(numCourses, prerequisites);

    cout << ret << endl;



}

//官方题解
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> indeg;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0;
        while (!q.empty()) {
            ++visited;
            int u = q.front();
            q.pop();
            for (int v: edges[u]) {
                --indeg[v];
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        return visited == numCourses;
    }
};
