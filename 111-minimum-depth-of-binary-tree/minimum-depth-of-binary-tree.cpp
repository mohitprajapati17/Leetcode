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
    int ans=INT_MAX;
    void dfs(TreeNode * node,int depth){
        if(node==NULL) return;
        // ans=max(ans,depth);
        if(!node->left&&!node->right) ans=min(ans,depth);
        dfs(node->left,depth+1);
        dfs(node->right,depth+1);
    }

    int minDepth(TreeNode* root) {
        dfs(root,1);
         if(ans==INT_MAX) return 0;

        return ans;
    }
};