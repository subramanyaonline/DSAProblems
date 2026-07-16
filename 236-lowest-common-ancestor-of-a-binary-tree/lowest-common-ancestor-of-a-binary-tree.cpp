/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* find(TreeNode* root, TreeNode* p , TreeNode* q){
        if(root==p) return p ; 
        if(root==q) return q ; 
        if(!root) return nullptr ; 
        TreeNode* left = find(root->left,p,q) ; 
        TreeNode* right = find(root->right,p,q) ; 
        if(left && right) return root ; 
        else if(left) return left ; 
        else if(right) return right ; 
        else return nullptr ; 
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root,p,q) ; 
    }
};