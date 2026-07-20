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
    bool searchBST(TreeNode* root, int target){
        if(!root) return false ; 
        if(root->val == target ) return true ; 
        return searchBST(root->left,target) || searchBST(root->right,target) ;
    }

    int findInorderSuccessor(TreeNode* root){
        if(!root->left) return root->val ; 
        return findInorderSuccessor(root->left) ; 
    }

    TreeNode* deletenode(TreeNode* root, int target){
        if(!root) return root ; 

        if(root->val==target){
            if(!root->left && !root->right) return nullptr ; 
            else if(!root->left && root->right) return root->right ;  
            else if(root->left && !root->right) return root->left ; 
            else {//two valid subtrees 
                int newval = findInorderSuccessor(root->right) ; 
                root->right = deletenode(root->right,newval) ;
                root->val = newval ;  
            }
        }else if(root->val>target){
            root->left = deletenode(root->left,target) ;//dont return this itself, as this returns the child node and you will end up loosing all the node values which satisfies this condition . 
        }else{
            root->right = deletenode(root->right,target) ; 
        }
        return root ; 
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!searchBST(root,key)) return root ; 

        return deletenode(root,key) ; 
    }
};