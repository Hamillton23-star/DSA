class Solution {
public:
    int result = 0;

    vector<int> dfs(TreeNode* node, int distance) {
        if (!node) return {};

        // Leaf node
        if (!node->left && !node->right)
            return {1}; // distance = 1 from leaf to parent

        vector<int> left = dfs(node->left, distance);
        vector<int> right = dfs(node->right, distance);

        for (int l : left) {
            for (int r : right) {
                if (l + r <= distance)
                    result++;
            }
        }

        vector<int> current;
        for (int l : left) if (l + 1 <= distance) current.push_back(l + 1);
        for (int r : right) if (r + 1 <= distance) current.push_back(r + 1);
        return current;
    }

    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return result;
    }
};
