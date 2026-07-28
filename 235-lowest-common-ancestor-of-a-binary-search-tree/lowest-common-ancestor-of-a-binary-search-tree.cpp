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
    void find(TreeNode* root, TreeNode* target, vector<TreeNode*> &path){      
        path.push_back(root) ; 
        if(root==target) return ; 
        if(target->val<root->val)
            find(root->left,target,path) ;
        else
            find(root->right,target,path) ; 
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vecpath1 ; 
        vector<TreeNode*> vecpath2 ; 
        find(root,p,vecpath1) ; 
        find(root,q,vecpath2) ; 

        TreeNode* LCA ; 
        for(int i=0;i<min(vecpath1.size(),vecpath2.size());++i){
            cout<<vecpath1[i]->val<<" "<<vecpath2[i]->val<<endl ;

            if(vecpath1[i]==vecpath2[i]) LCA = vecpath1[i] ;             
            else break ;

        }
        return LCA ; 
    }
};