class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;

        TreeNode* root = new TreeNode(preorder[start]);

        
        int rightStart = start + 1;
        while (rightStart <= end && preorder[rightStart] < root->val)
            rightStart++;

        root->left = buildTree(preorder, start + 1, rightStart - 1);
        root->right = buildTree(preorder, rightStart, end);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildTree(preorder, 0, preorder.size() - 1);
    }
};
