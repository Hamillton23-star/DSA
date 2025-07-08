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
     map<int,int> mpp;
     int maxd=0;
     TreeNode* lca(TreeNode* root){
     if(root==NULL || mpp[root->val]==maxd)return root;

      TreeNode* l= lca(root->left);
       TreeNode* r= lca(root->right);
     if(l && r)return root;
     else if(l)return l;
     else return r;
     }
     void depth(int d ,TreeNode* root){
         if(!root) return;
          maxd=max(maxd,d);
         mpp[root->val]=d;
        depth(d+1,root->left);
        depth(d+1,root->right);
     }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(0,root);
        return lca(root);
    }
};