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

    int getmaxsum(TreeNode* root, int &maxpath){ //maxsum , cursum 
        if(!root) return 0 ; 

        int left = getmaxsum(root->left,maxpath) ; 
        int right = getmaxsum(root->right,maxpath) ; 

        maxpath = max({root->val,left+right+root->val,maxpath,max(left,right)+root->val}) ; 

        int retval = max(max(left,right)+root->val , root->val) ; 
        if(retval<0) retval = 0 ; 

        return retval ; 
    }

    int maxPathSum(TreeNode* root) {
        int ans = -1000 ; 
        getmaxsum(root,ans) ; 
        return ans ; 
    }
};