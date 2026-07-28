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
    int goodNodes(TreeNode* root, int prevmax) {
        if(!root) return 0 ; 
        int nextmax = max(root->val,prevmax) ; 

        int left = goodNodes(root->left,nextmax) ; 
        int right = goodNodes(root->right,nextmax) ; 
        if(root->val>=prevmax) 
            return  left + right + 1 ; 

        return left + right ; 

    }

    int goodNodes(TreeNode* root) {
        return goodNodes(root,-1e4) ; 
    }
};