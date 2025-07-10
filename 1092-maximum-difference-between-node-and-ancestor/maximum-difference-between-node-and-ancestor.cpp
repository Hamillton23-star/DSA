class Solution {
public:
    int dfs(TreeNode* root, int curMax, int curMin) {
        if (!root) return curMax - curMin;

        curMax = max(curMax, root->val);
        curMin = min(curMin, root->val);

        int left = dfs(root->left, curMax, curMin);
        int right = dfs(root->right, curMax, curMin);

        return max(left, right);
    }

    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};
