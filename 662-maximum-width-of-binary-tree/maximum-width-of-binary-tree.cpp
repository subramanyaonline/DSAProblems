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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q ; 
        q.push({root,0}) ; 
        long long maxwidth = 1 ; 

        while(!q.empty()){
            long long size = q.size() ; 
            long long  start = q.front().second ; //first ele index in a level
            long long end= q.back().second ; //last ele index in a level
            maxwidth = max(maxwidth, end-start+1);

            for(int i=0;i<size;i++){
                auto p = q.front() ; 
                q.pop() ; 
                TreeNode* node = p.first ;
                long long index = p.second ; 
                long long newindex = index-start ; 

                if(node->left) q.push({node->left,newindex*2 + 1}) ; 
                if(node->right) q.push({node->right,newindex*2+2}) ; 
            }
        }

        return maxwidth ; 
    }
};