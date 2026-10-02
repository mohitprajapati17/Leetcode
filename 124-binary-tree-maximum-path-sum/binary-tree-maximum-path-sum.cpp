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
    int   rec(TreeNode * root,int  &maxi){
        if(root==nullptr) return 0;
        int left=rec(root->left,maxi);
        int right=rec(root->right,maxi);
        if(left<0) left=0;
        if(right<0) right=0;
        maxi=max(maxi,root->val+left+right);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
         rec(root,maxi);
         return maxi;


    }
};