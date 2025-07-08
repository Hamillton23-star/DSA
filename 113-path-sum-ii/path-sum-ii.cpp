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
    void inorder(TreeNode* root,int sum,int target,vector<int>& temp,vector<vector<int>>& ans){
     if(root==NULL)return;
       sum+=root->val;
         temp.push_back(root->val);
     if(root->left==NULL && root->right==NULL){
        if(sum==target){
            ans.push_back(temp);
        }
        temp.pop_back();
        return;
     }

     inorder(root->left,sum,target,temp,ans);
     inorder(root->right,sum,target,temp,ans);
    temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
       vector<vector<int>> ans;
       vector<int> temp;
       inorder(root,0,target,temp,ans);
       return ans; 
    }
};