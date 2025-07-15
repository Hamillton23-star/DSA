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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    map<int,TreeNode*> mpp;
    set<int> child;
    for(auto it: descriptions){
     int parent=it[0];
     int childval=it[1];
     int isleft=it[2];
     if(!mpp.count(parent)){
        mpp[parent]=new TreeNode(parent);
     }
     if(!mpp.count(childval)){
         mpp[childval]=new TreeNode(childval);
     }
     if(isleft){
        mpp[parent]->left=mpp[childval];
     }
     else{
          mpp[parent]->right=mpp[childval];
     }
     child.insert(childval);
    }
    for(auto it : mpp){
        int val=it.first;
        TreeNode* node=it.second;
        if(child.find(val)==child.end()) return node;
    }
   return nullptr;
    }
};