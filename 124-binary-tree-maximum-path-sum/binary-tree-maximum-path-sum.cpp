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

    pair<int,int> getmaxsum(TreeNode* root){ //maxsum , cursum 
        if(!root) return {-1000,0} ; 
        pair<int,int> leftcall = getmaxsum(root->left) ; 
        pair<int,int> rightcall = getmaxsum(root->right) ; 

        int childmaxsum = max(leftcall.first,rightcall.first) ; 

        int leftheightsum = leftcall.second ; 
        int rightheightsum = rightcall.second ; 
        int curheightsum = max(leftheightsum,rightheightsum) + root->val ; 

        int a , b ; 
        if(curheightsum<0){
            b = 0 ; 
            a = max(curheightsum,childmaxsum) ; 
        }
        else {
            b = curheightsum ; 
            a = max(childmaxsum,max(curheightsum+min(leftheightsum,rightheightsum),curheightsum)) ;
        }
        return {a,b} ; 
    }

    int maxPathSum(TreeNode* root) {
        return getmaxsum(root).first ; 
    }
};