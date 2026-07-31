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
    pair<int,int> maxrob(TreeNode* root){//first-buying child,  second-skipping child/buying grandchild or maxtillgrandchild
        if(!root) return {0,0}; 

        auto pleft = maxrob(root->left) ; 
        auto pright = maxrob(root->right) ; 

        int curbest = max(
            pleft.second + pright.second + root->val,
            pleft.first + pright.first //child best 
        ) ; 
        int childbest = pleft.first + pright.first ;  

        return {curbest,childbest} ; 
    }

    int rob(TreeNode* root) {
        auto ans = maxrob(root) ; 
        return max(ans.first,ans.second) ; 
    }
};