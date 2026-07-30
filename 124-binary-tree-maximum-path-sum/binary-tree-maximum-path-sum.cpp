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

        int left = max(0,getmaxsum(root->left,maxpath)) ; 
        int right = max(0,getmaxsum(root->right,maxpath)) ; 

        maxpath = max(maxpath , left + right + root->val) ; 
        return max(left,right) + root->val ; 
    }

    int maxPathSum(TreeNode* root) {
        int ans = -1000 ; 
        getmaxsum(root,ans) ; 
        return ans ; 
    }
};