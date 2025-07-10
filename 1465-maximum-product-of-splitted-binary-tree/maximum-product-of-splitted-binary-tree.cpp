class Solution {
public:
    const int MOD=1e9+7;
    long Sum=0,maxProd=0;
    int totalSum(TreeNode* root){
        if(!root) return 0;

        int leftSubTreeSum=totalSum(root->left);
        int rightSubTreeSum=totalSum(root->right);
        int subTreeSum=root->val+leftSubTreeSum+rightSubTreeSum;

        long remainingSum=Sum-subTreeSum;

        maxProd=max(maxProd,remainingSum*subTreeSum);

        return subTreeSum;
    }
    int maxProduct(TreeNode* root) {
        if(!root) return 0;

        maxProd=0;

        Sum=totalSum(root);

        totalSum(root);
        return maxProd%MOD;
    }
};