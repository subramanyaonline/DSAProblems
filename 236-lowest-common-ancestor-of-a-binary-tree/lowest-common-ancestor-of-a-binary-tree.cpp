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
    bool findpath(TreeNode* root, TreeNode* node, vector<TreeNode*> &path){
        if(!root) return false ; 
        path.push_back(root) ; 
        if(node == root) return true ; 
        
        if(findpath(root->left , node, path)) return true ; 
        if(findpath(root->right,node,path)) return true ; 
        
        path.pop_back() ; 
        return false ; 
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathp ; 
        vector<TreeNode*> pathq ; 
        findpath(root,p,pathp) ; 
        findpath(root,q,pathq) ; 
        
        cout<<pathp.size(); 
        cout<<pathq.size() ; 
        //last common node in the paths of both , will be the lowest common ancestor
        int i; 
        for(i=0; i<min(pathq.size(),pathp.size()) ; ++i){
            if(pathp[i]!=pathq[i]) break ; 
        }
        return pathp[i-1] ; 
    }
};