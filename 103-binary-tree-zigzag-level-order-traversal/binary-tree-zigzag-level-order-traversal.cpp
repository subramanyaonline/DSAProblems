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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans ; 
        if(!root) return ans ; 

        int level = 0 ; 

        stack<TreeNode*> st ; 
        queue<TreeNode*> q ; 
        q.push(root) ;  
        


        while(!q.empty()){
            
            level++ ; 
            vector<int> veclevel ; 

            while(!q.empty()){
                TreeNode* top = q.front() ; 
                q.pop() ; 
                st.push(top) ; 
            }

            int size = st.size() ; 

            while(size--){
                TreeNode* top = st.top() ; 
                st.pop() ; 

                veclevel.push_back(top->val) ; 

                if(level%2==0){
                    if(top->right) q.push(top->right) ; 
                    if(top->left) q.push(top->left) ; 
                }else{
                    if(top->left) q.push(top->left) ; 
                    if(top->right) q.push(top->right) ; 
                }
            }
            ans.push_back(veclevel) ; 
        }

        return ans ; 
    }
};