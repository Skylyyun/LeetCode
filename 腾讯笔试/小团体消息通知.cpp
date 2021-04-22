#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//第二题 广度优先搜索
//对加入小团体的人创建邻接表
long long getPeopleNum(unordered_map<long long, unordered_set<long long>> Graph) {
    queue<long long> Q;
    unordered_set<long long> hash;
    long long num = 0;

    Q.push(0);
    hash.insert(0);

    while(!Q.empty()) {
        num = Q.front(); Q.pop();
        for(auto n : Graph[num]) {
            if (auto it = hash.find(n) != hash.end()) {
                continue;
            }

            hash.insert(n);
            Q.push(n);
        }
    }

    return hash.size();
}

int main(void) {
    long long n, m, x, val;
    unordered_map<long long, unordered_set<long long>> Graph;
    unordered_set<long long> storenum;
    unordered_set<long long> numcopy;
    long long result = 0;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        storenum.clear();
        cin >> x;
        for (int j = 0; j < x; j ++) {
            cin >> val;
            storenum.insert(val);
        }

        for (auto a : storenum) {
            numcopy = storenum;
            numcopy.erase(a);
            if (auto it = Graph.find(a) != Graph.end()) {
                for (auto i : numcopy) {
                    Graph[a].insert(i);
                }
            }
            else
                Graph.insert({a, numcopy});
        }
    }

    result = getPeopleNum(Graph);

    cout << result << endl;
}