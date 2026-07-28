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

    pair<long long,long long> isValid(TreeNode* root, bool &result){
        if(!root) return {LLONG_MAX,LLONG_MIN} ; 

        long long rootval = root->val ;
        auto left = isValid(root->left , result) ; 
        auto right = isValid(root->right , result) ; 

        long long leftLargest = left.second ; 
        long long rightSmallest = right.first ; 

        if(leftLargest>=root->val || rightSmallest<=root->val){
            result = false ; 
            return {INT_MIN,INT_MAX} ;
        }

        long long minTillNow = left.first ; 
        long long maxTillNow = right.second ; 
        minTillNow = min(minTillNow,rootval) ; 
        maxTillNow = max(maxTillNow,rootval) ;  
        
        return {minTillNow,maxTillNow} ; 
    }

    bool isValidBST(TreeNode* root) {
        bool result = true ;
        isValid(root,result) ; 
        return result ; 
    }

};