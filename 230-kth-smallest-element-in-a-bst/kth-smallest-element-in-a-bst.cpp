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
    void findinorder(TreeNode* root, vector<int>& temp) {
        if (!root) return;

        findinorder(root->left, temp);
        temp.push_back(root->val);
        findinorder(root->right, temp);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> temp;
        findinorder(root, temp);
        return temp[k - 1];
    }
};
