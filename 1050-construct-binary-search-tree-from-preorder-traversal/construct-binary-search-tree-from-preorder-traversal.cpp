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
   TreeNode* maketree(vector<int>& preorder,int& i,int bound){
    if(i==preorder.size() || preorder[i]>bound)return nullptr;

    TreeNode* root=new TreeNode(preorder[i++]);
    root->left= maketree(preorder,i,root->val);
    root->right= maketree(preorder,i,bound);
    return root;
   }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
      return  maketree(preorder,i,INT_MAX);
    }
};