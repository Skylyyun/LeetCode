/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        //如果没有的话，返回空串
        if(root == nullptr) {
            return result;
        }

        //1、创建一个队列，把起始节点都放到里面去
        queue<TreeNode* > level;
        level.push(root);

        //2. while 队列不为空，处理队列中的节点，并拓展出新的节点
        while(!level.empty()) {
            vector<int> eachLevel;
            int num = level.size();

            //通过上一层的节点拓展下一层的节点
            for (int i = 0; i < num; i++) {
                TreeNode* node = level.front();
                level.pop();
                eachLevel.push_back(node->val);

                if (node->left != nullptr) {
                    level.push(node->left);
                }

                if (node->right != nullptr) {
                    level.push(node->right);
                }
            }
            result.push_back(eachLevel);
        }
        return result;
    }
};