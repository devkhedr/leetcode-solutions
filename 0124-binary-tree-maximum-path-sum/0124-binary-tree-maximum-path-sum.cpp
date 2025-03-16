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
    int max_sum = INT_MIN;
    int solve(TreeNode* node) {
        if (!node) return 0;
        int left_cost = max(0, solve(node->left));
        int right_cost = max(0, solve(node->right));
        int current_sum = node->val + left_cost + right_cost;
        max_sum = max(max_sum, current_sum);
        return node->val + max(left_cost, right_cost);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return max_sum;
    }
};
