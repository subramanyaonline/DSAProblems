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
    bool dfs(TreeNode* root, int targetSum, int curSum){
        if(!root) return false ; 
        if(!root->left && !root->right && curSum==targetSum) return true ; 
        else if(!root->left && !root->right) return false ; 
        int left = 0, right =0; 
        if(root->left) left = dfs(root->left,targetSum,curSum+root->left->val) ; 
        if(root->right) right = dfs(root->right,targetSum,curSum+root->right->val) ; 
        return left||right ; 
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false ; 
        return dfs(root,targetSum,root->val) ; 
    }
};