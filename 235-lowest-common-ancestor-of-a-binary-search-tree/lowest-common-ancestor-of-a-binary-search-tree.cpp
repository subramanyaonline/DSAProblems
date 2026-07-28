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
    bool find(TreeNode* root, TreeNode* target, vector<TreeNode*> &path){
        if(!root) return false; 
        
        path.push_back(root) ; 
        if(root==target) return true ; 
        if(find(root->left,target,path)) return true ; 
        if(find(root->right,target,path)) return true ; 
        path.pop_back() ; 
        return false ;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vecpath1 ; 
        vector<TreeNode*> vecpath2 ; 
        find(root,p,vecpath1) ; 
        find(root,q,vecpath2) ; 

        TreeNode* LCA ; 
        for(int i=0;i<min(vecpath1.size(),vecpath2.size());++i){
            if(vecpath1[i]==vecpath2[i]) LCA = vecpath1[i] ; 
            else break ;
        }
        return LCA ; 
    }
};