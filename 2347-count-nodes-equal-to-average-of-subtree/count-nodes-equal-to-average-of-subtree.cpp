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
    int ans=0;
    pair<int,int> t(TreeNode *root){
        if(root==nullptr)  return {0,0};
        pair<int,int> l=t(root->left);
        pair<int,int> r=t(root->right);
        int x=root->val+l.first+r.first;
        int y=1+l.second+r.second;
        if((x/y)==root->val){
            ans++;
        }
        return {x,y};

    }
    int averageOfSubtree(TreeNode* root) {
        pair<int,int> x=t(root);
        return ans;
    }
};