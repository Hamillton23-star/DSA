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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         int n=postorder.size();
       map<int,int> track;
       for(int i=0;i<n;i++){
        track[inorder[i]]=i;
       }
       return maketree(postorder,0,n-1,inorder,0,n-1,track);
    }
     TreeNode* maketree(vector<int>& postorder,int start1,int end1,vector<int>& inorder,int start2,int end2,map<int,int>& track){

     if(start1> end1 || start2> end2) return NULL;

     TreeNode* root= new TreeNode(postorder[end1]);
     int inroot=track[postorder[end1]];
     int numsleft=inroot-start2;

     root->left=maketree(postorder,start1,start1+numsleft-1,inorder,start2,inroot-1,track);
     root->right=maketree(postorder,start1+numsleft,end1-1,inorder,inroot+1,end2,track);
      
    return root;
    }
};