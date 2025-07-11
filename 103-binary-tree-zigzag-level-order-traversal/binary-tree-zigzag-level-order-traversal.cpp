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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ans;
      if(root==NULL)return ans;
      queue<TreeNode*> q;
      q.push(root);
      int p=0;
      while(!q.empty()){
        int n=q.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();
            temp.push_back(node->val);
            if(node->left!=NULL)q.push(node->left);
            if(node->right!=NULL)q.push(node->right);
        }
       if(p==1) {
         reverse(temp.begin(),temp.end());
         ans.push_back(temp);
         p=!p;
       }
       else{
          ans.push_back(temp);
          p=!p;
       }
      }  
      return ans;
    }
};