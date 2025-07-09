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
    int cnt = 0;

    
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

   
    int countSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + countSum(root->left) + countSum(root->right);
    }

    
    int averageOfSubtree(TreeNode* root) {
        if (!root) return 0;

        int sum = countSum(root);
        int nodes = countNodes(root);

        if (root->val == sum / nodes) cnt++;

        averageOfSubtree(root->left);
        averageOfSubtree(root->right);

        return cnt;
    }
};
