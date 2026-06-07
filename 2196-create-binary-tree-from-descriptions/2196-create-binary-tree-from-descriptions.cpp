/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        std::unordered_map<int, std::vector<std::vector<int>>> childrens;
        std::unordered_set<int> seen;
        for (std::vector<int>& edge : descriptions) {
            childrens[edge[0]].push_back({edge[1], edge[2]});
            seen.insert(edge[1]);
        }
        int startVertex = 0;
        for (std::vector<int>& edge : descriptions) {
            if (!seen.count(edge[0])) {
                startVertex = edge[0];
                break;
            }
        }
        TreeNode* root = new TreeNode(startVertex);
        std::vector<TreeNode*> curNodes = {root}, nextNodes;
        while (!curNodes.empty()) {
            for (TreeNode* node : curNodes) {
                for (std::vector<int>& edge : childrens[node->val]) {
                    TreeNode* child = new TreeNode(edge[0]);
                    if (edge[1]) node->left = child;
                    else node->right = child;
                    nextNodes.push_back(child);
                }
            }
            curNodes = nextNodes;
            nextNodes.clear();
        }
        return root;
    }
};