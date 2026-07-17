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
    string dft(TreeNode* &root, vector<TreeNode*> &duplicate , unordered_map<string,int> &map){
        if(!root) return "#" ; 
        string str ; 
        str = dft(root->left,duplicate,map) + ',' + dft(root->right,duplicate,map) + ',' + to_string(root->val) ; 
        
        map[str]++ ; 
        if(map[str]==2){
            duplicate.push_back(root) ; 
            cout<<str<<endl;
        }

        return str ; 
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> duplicate ;
        unordered_map<string,int> map ; 

        dft(root,duplicate,map) ; 

        return duplicate ; 
    }
};