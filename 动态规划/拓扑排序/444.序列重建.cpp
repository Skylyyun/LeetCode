class Solution {
public:
    /**
     * @param org a permutation of the integers from 1 to n
     * @param seqs a list of sequences
     * @return true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        //创建了两个map,pos记录位置，
        unordered_map<int, int> pos, pre;
        //记住每个值的位置
        for (int i = 0; i < org.size(); ++i) pos[org[i]] = i;
        for (auto& seq : seqs) {
            for (int i = 0; i < seq.size(); ++i) {
                //如果没有在pos中找到就返回false;
                if (pos.find(seq[i]) == pos.end()) {
                    return false;
                }
                //如果顺序不一样还是返回false;
                if (i > 0 && pos[seq[i - 1]] >= pos[seq[i]]) {
                    return false;
                }

                //让pre记录前置节点在org的位置
                if (pre.find(seq[i]) == pre.end()) {
                    pre[seq[i]] = (i > 0) ? pos[seq[i - 1]] : -1;
                } else {
                    pre[seq[i]] = max(pre[seq[i]], (i > 0) ? pos[seq[i - 1]] : -1);
                }
            }
        }

        //对应pre和org的前置节点位置
        for (int i = 0; i < org.size(); ++i) {
            if (pre[org[i]] != i - 1)
                return false;
        }
        return true;
    }
};