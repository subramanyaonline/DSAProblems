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
    int goodNodes(TreeNode* root, stack<pair<int,int>> &st, int level) {
        if(!root) return 0 ; 
        if(!st.empty() && st.top().first<root->val){
            st.push({root->val,level}) ; 
        }
        else if(st.empty()) st.push({root->val,level}) ; 

        int left = goodNodes(root->left,st,level+1) ; 
        int right = goodNodes(root->right,st,level+1) ; 
        
        int retval = 0 ; 

        if(!st.empty() && st.top().second==level){
            st.pop() ; 
            return left + right + 1 ; 
        }
        else if(!st.empty() && st.top().first==root->val){
            return left + right + 1 ; 
        }
        return left + right ; 
    }

    int goodNodes(TreeNode* root) {
        stack<pair<int,int>> st ; 
        return goodNodes(root,st,0) ;    
    }
};