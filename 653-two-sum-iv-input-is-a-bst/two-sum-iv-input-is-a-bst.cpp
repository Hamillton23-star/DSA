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
     void findinorder(TreeNode* root,vector<int>& ans){
        if(!root) return;

        findinorder(root->left,ans);
        ans.push_back(root->val);
        findinorder(root->right,ans);
     }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        
       findinorder(root,ans);
        int n=ans.size();
        int i=0,j=n-1;
        int sum=0;
        while(i<j){
          sum=ans[i]+ans[j];

          if(sum==k)return true;

          else if(sum< k){
           i++;
          }
          else{
            j--;
          }
        }
       return false;
    }
};