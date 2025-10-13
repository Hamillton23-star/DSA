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
    int countNodes(TreeNode* root) {
    if(!root) return 0; 
    int lh=countleft(root);
    int rh=countright(root);
    if(lh==rh) return (1<<lh)-1;
    
    return 1+countNodes(root->left)+countNodes(root->right);
    }

    int countleft(TreeNode* root){
     TreeNode* temp=root;
      int count=0;
     while(temp!=NULL){
        temp=temp->left;
        count++;
      }
     return count;
    }
 
     int countright(TreeNode* root){
     TreeNode* temp1=root;
      int count1=0;
     while(temp1!=NULL){
     
        temp1=temp1->right;
        count1++;
     }
     return count1;
    }

};