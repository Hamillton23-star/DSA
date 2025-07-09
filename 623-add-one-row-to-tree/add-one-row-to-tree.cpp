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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
         if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
    queue<pair<TreeNode*,int>> q;
    q.push({root,1});

    while(!q.empty()){         
      TreeNode* node=q.front().first;
       int level=q.front().second;
       q.pop();

       if(level==depth-1){
            TreeNode* newleft=new TreeNode(val);
             TreeNode* newright=new TreeNode(val);
            newleft->left=node->left;
            newright-> right=node->right;   
        node->left=newleft;
        node->right=newright;    
       }
       else{
     if(node->left) q.push({node->left,level+1});
      if(node->right) q.push({node->right,level+1});
     } 
    }
    return root;
    }
};