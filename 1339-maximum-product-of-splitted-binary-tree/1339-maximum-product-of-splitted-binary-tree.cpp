// 0 ms recursion + iteration
class Solution {
public:
    static void dfsSum(TreeNode* r) noexcept {
        if (r->left) {
            dfsSum(r->left);
            r->val += r->left->val;
        }
        if (r->right) {
            dfsSum(r->right);
            r->val += r->right->val;
        }
    }
    static int maxProduct(TreeNode* root) noexcept {
        dfsSum(root);

        long totalSum = root->val;
        long mx = 0;
        vector<TreeNode*> stack = {root};
         while (!stack.empty()) {
            const TreeNode* r = stack.back();
            stack.pop_back();
            if (r->left) {
                const long subSum = r->left->val;
                mx = max(mx, subSum * (totalSum - subSum));
                stack.push_back(r->left);
            }
            if (r->right) {
                const long subSum = r->right->val;
                mx = max(mx, subSum * (totalSum - subSum));
                stack.push_back(r->right);
            }
        }
        return mx % 1000000007;
    }
};