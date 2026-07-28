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
    bool isValidBST(TreeNode* root,long long low, long long high){
        if(!root) return true ; 
        if(root->val<= low || root->val>=high ) return false ; 
        bool left = isValidBST(root->left,low,root->val) ; 
        bool right = isValidBST(root->right,root->val,high) ; 
        return left&&right ;
    }
//so the intuition goes like , every node on the left should be less than the root and every node on right should be greater, so why not send boundaries itself to the next root . 
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LLONG_MIN,LLONG_MAX) ;
    }
};