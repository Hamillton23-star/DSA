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
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> ans;
      if(root==NULL) return ans;
      TreeNode* temp=root;
      while(temp!=NULL){
        if(temp->left==NULL){
            ans.push_back(temp->val);
            temp=temp->right;
        }
        else {
            TreeNode* cur=temp->left;
            while(cur->right!=NULL && cur->right!=temp){
                cur=cur->right;
            }
            if(cur->right==NULL){
                cur->right=temp;
                temp=temp->left;
                // thread ban gyi
            }

            else{
                //thread toot gyi
                cur->right=NULL;
                ans.push_back(temp->val);
                temp=temp->right;
            }
        }
      }
      return ans;
    }
};