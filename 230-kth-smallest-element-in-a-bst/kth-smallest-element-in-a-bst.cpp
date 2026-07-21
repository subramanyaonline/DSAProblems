/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    //you can also pass one ans variable , which is a reference so that you dont need to return -1 every time and just return void. if count==k , ans = root->val , thats it . 
    //helper(root,k,&count,&ans)
    
    int helper(TreeNode* root, int k, int &count) {
        if (!root) return -1;

        int left = helper(root->left, k, count);
        if (left != -1) return left;

        count++;
        if (count == k) return root->val;

        return helper(root->right, k, count);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return helper(root, k, count);
    }
};