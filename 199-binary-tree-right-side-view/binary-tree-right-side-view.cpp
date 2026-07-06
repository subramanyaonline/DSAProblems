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
    int findheight(TreeNode* root){
        if(!root) return 0 ; 
        return max(findheight(root->left),findheight(root->right))+1; 
    }

    void rightview(vector<int>& ans,vector<bool>& level, TreeNode* root,int curlevel){
        if(!root) return ; 
        if(!level[curlevel]){
            ans[curlevel] = root->val ;
            level[curlevel] = true ;
        }
        rightview(ans,level,root->right,curlevel+1) ; 
        rightview(ans,level,root->left,curlevel+1) ; 
    }

    vector<int> rightSideView(TreeNode* root) {
        //if(!root) return {} ;
        int h = findheight(root) ; 
        vector<bool> level(h) ; 

        vector<int> ans(h) ; 
        rightview(ans,level,root,0) ; 
        return ans ; 
    }
};