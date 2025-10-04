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
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> ans;
       if(root==NULL){
        return ans;
       } 
       stack<TreeNode*> st;
       TreeNode* node=root;
       TreeNode* lastvisit=NULL;

       while(!st.empty() || node!=NULL){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else{
            TreeNode* cur=st.top();
            if(cur->right!=NULL && cur->right!=lastvisit){
             node=cur->right;
             } 
             else{
                ans.push_back(cur->val);
                lastvisit=cur;
                st.pop();
             }
        }
       }
       return ans;
    }
};