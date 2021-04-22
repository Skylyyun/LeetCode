/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    //1. Calulate in degree 2. (0 in degree) node to in queue 3. Uses BFS to abtain the results
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        //创建一个拓扑排序后的vector
        vector<DirectedGraphNode*> result;

        //判断图是否为空
        if (graph.size() == 0) {
            return result;
        }

        //1. count indegree , 计算入度，以完成拓扑排序
        unordered_map<DirectedGraphNode*, int> indegree = getIndegree(graph);

        //2. 获得入度为0的点，以此开始排序
        vector<DirectedGraphNode*> startNodes = getStartNodes(indegree,graph);

        //3. bfs , 获得拓扑排序的序列
        result = bfs(indegree, startNodes);

        //最后还要考虑是否遍历了所有得点
        if(result.size() == graph.size()) {
            return result;
        }

        result.clear();
        return result;
    }

    unordered_map<DirectedGraphNode*, int> getIndegree(vector<DirectedGraphNode*>& graph) {
        unordered_map<DirectedGraphNode*, int> indegree;
        for (auto n : graph) {
            for (auto neighbor : n->neighbors) {
                if (auto it = indegree.find(neighbor) != indegree.end()) {
                    indegree[neighbor] += 1;
                }
                indegree[neighbor] = 1;
            }
        }
        return indegree;
    }

    vector<DirectedGraphNode*> getStartNodes(unordered_map<DirectedGraphNode*, int>& indegree, 
            vector<DirectedGraphNode*>& graph) {
        vector<DirectedGraphNode*> startNodes;
        for (auto n : graph) {
            if (indegree[n] == 0) {
                startNodes.push_back(n);
            }
        }
        
        return startNodes;
    }

    vector<DirectedGraphNode*> bfs(unordered_map<DirectedGraphNode*, int>& indegree,
            vector<DirectedGraphNode*>& startNodes) {
        vector<DirectedGraphNode*> result;
        queue<DirectedGraphNode*> Q;
        
        for (auto n : startNodes) {
            Q.push(n);
            result.push_back(n);
        }
        
        while(!Q.empty()) {
            auto node = Q.front(); Q.pop();
            for (auto neighbor: node->neighbors) {
                //不会重复访问，因为会减到-1
                indegree[neighbor] --;
                if (indegree[neighbor] == 0) {
                    Q.push(neighbor);
                    result.push_back(neighbor);
                }
            }
        }
        
        return result;
    }

};