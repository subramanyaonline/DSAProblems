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
    void kthSmallest(TreeNode* root, vector<int> &ans){
        if(!root) return ; 
        kthSmallest(root->left,ans) ; 
        ans.push_back(root->val) ; 
        kthSmallest(root->right, ans) ; 
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder ; 
        kthSmallest(root,inorder) ; 
        //for(int ele : inorder) cout<<ele<< " " ; 
        return inorder[k-1] ; 
    }
};