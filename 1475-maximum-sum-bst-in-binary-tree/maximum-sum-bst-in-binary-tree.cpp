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

class Node{
    public :
    int maxNode,minNode,sum,maxSum;

    Node(int minNode,int maxNode,int sum, int maxSum){
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->sum = sum;
        this->maxSum = maxSum ; 
    }
};


class Solution {
public:
    Node maxsum(TreeNode* root){
        if(!root) return Node(INT_MAX,INT_MIN,0,0) ;

        Node left = maxsum(root->left) ; 
        Node right = maxsum(root->right) ;

        //the subtree is not bst . 
        if(left.maxNode >= root->val || right.minNode <=root->val){
            return Node(INT_MIN,INT_MAX,0,max(left.maxSum,right.maxSum)) ; 
        }

        //subtree is bst 
        int cursum = left.sum + right.sum + root->val ; 
        int bestsum = max(max(left.maxSum,right.maxSum),cursum) ; //this line is there because , all node values might be negative , so even though bst is valid cursum might not best , best would be 0 (with zero nodes rt) ; if only positive elements , then if bst, you can directly assign it to maxsum, but since negatives , we cannot do that here. 

        int minn = min(left.minNode,root->val) ; 
        int maxx = max(right.maxNode,root->val) ; 
        return Node(minn,maxx,cursum,bestsum) ; 

    }

    int maxSumBST(TreeNode* root) {
        return maxsum(root).maxSum ; 
        //return ans.maxSum ; 
    }
};