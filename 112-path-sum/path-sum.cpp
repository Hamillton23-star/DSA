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
     
    bool inorder(TreeNode* root,int sum, int target){
     if(root==NULL)return false;

     sum+=root->val;

     if(root->left==NULL && root->right==NULL){
        if(sum==target)return true;
        return false;
     }
   
     bool left=inorder(root->left,sum,target);
     
     bool right=inorder(root->right,sum,target);
     
     return left || right; 
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
     return  inorder(root,0,targetSum);
    }
};