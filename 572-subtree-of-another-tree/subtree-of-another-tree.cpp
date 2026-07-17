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
    bool isIdentical(TreeNode* root, TreeNode* subRoot){
        if(!root && subRoot) return false ; 
        if(root && !subRoot) return false ; 
        if(!root && !subRoot) return true ; 
        if(root->val != subRoot->val) return false ; 

        //if both root->val and subRoot->val are equal, then 
        if(isIdentical(root->left,subRoot->left) && isIdentical(root->right,subRoot->right)) return true ; 
        return false ; 
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false ; 
        if(isIdentical(root,subRoot))  return true ; 
        if(isSubtree(root->left,subRoot)) return true ; 
        if(isSubtree(root->right,subRoot)) return true ; 
        return false ; 
    }
};