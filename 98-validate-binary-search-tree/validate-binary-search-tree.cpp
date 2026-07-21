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

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
    
    bool isValidBST(TreeNode* root, TreeNode* leftbound , TreeNode* rightbound){
        if(!root) return true ; 

        if(leftbound && root->val <= leftbound->val) return false ; 
        if(rightbound && root->val >= rightbound->val) return false ; 

        return isValidBST(root->left,leftbound,root) && isValidBST(root->right,root, rightbound) ;
    }

};