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
    TreeNode* findLCA(TreeNode* root, TreeNode* leftTarget,TreeNode* rightTarget){
        if(root==leftTarget || root==rightTarget) return root ; 
        cout<<root->val<<" "; 
        if(leftTarget->val<root->val && rightTarget->val>root->val) return root ; 
        if(rightTarget->val < root->val) return findLCA(root->left,leftTarget,rightTarget) ; 
        return findLCA(root->right,leftTarget,rightTarget) ; 
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* leftTarget ; 
        TreeNode* rightTarget ; 
        if(p->val<q->val){
            leftTarget = p ; rightTarget = q ; 
        }else{
            leftTarget = q ; rightTarget = p ; 
        }
        return findLCA(root,leftTarget,rightTarget) ; 
    }
};