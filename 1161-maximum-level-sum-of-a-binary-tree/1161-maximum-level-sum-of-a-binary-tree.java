/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int bfs(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        int maxLevel = 0;
        int maxSum = Integer.MIN_VALUE;
        int level = 1;

        q.add(root);

        while(!q.isEmpty()) {
            int size = q.size();
            int sum = 0;

            for(int i = 0; i < size; i++) {
                TreeNode curr = q.poll();

                sum += curr.val;

                if(curr.left != null) {
                    q.add(curr.left);
                }

                if(curr.right != null) {
                    q.add(curr.right);
                }
            }

            if(sum > maxSum) {
                maxSum = sum;
                maxLevel = level;
            }

            level++;
        }

        return maxLevel;
    }

    public void dfsUtil(TreeNode root, List<Integer> list, int level) {
        if(root == null) {
            return;
        }

        if(list.size() > level) {
            list.set(level, list.get(level) + root.val);
        } else {
            list.add(root.val);
        }

        dfsUtil(root.left, list, level + 1);
        dfsUtil(root.right, list, level + 1);
    }

    public int dfs(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        int maxSum = Integer.MIN_VALUE;
        int maxLevel = -1;

        dfsUtil(root, list, 0);

        for(int i = 0; i < list.size(); i++) {
            if(maxSum < list.get(i)) {
                maxSum = list.get(i);
                maxLevel = i + 1;
            }
        }

        return maxLevel;
    }

    public int maxLevelSum(TreeNode root) {
        return dfs(root);
    }
}