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
    int rec(TreeNode * root, unordered_map<TreeNode*,int> &dp){
        if(root==nullptr) return 0;
        if(dp.find(root)!=dp.end()) return dp[root];
        int take =0;
        int not_take=0;
        take=root->val;
        if(root->left!=nullptr) {
            take=take+rec(root->left->left,dp)+rec(root->left->right,dp);
            not_take=not_take+rec(root->left,dp);
        }
        if(root->right!=nullptr){
            take=take+rec(root->right->left,dp)+rec(root->right->right,dp);
            not_take=not_take+rec(root->right,dp);
        }
        return dp[root]=max(take,not_take);

        
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> dp;
        return rec(root,dp);
    }
};