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
    vector<int>  ans;
    void R(TreeNode *node  ,  int  level){
        if(node==NULL)  return;
        if(ans.size()==level){
            ans.push_back(node->val);
        }

        R(node->right,level+1);
        R(node->left,level+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        R(root,0);
        return  ans;
    }
};