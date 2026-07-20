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

    void rootToLeaf(TreeNode* root, int targetsum,vector<vector<int>>&ans,vector<int>&path){
        if(!root->left && !root->right && targetsum==0){
            path.push_back(root->val) ; 
            ans.push_back(path) ; 
            path.pop_back() ; 
            return ; 
        }

        path.push_back(root->val) ; 
        if(root->left) rootToLeaf(root->left,targetsum-root->left->val,ans,path) ; 
        if(root->right) rootToLeaf(root->right,targetsum-root->right->val,ans,path) ; 
        path.pop_back() ;

        return ;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans ; 
        vector<int> path ; 
        if(!root) return ans ; 
        rootToLeaf(root,targetSum-root->val,ans,path) ; 
        return ans ;
    }
};