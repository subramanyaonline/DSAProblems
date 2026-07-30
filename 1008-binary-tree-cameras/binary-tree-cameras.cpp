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
    //0 - need cameras , 1-no need cameras,  2 - i have cameras 
    int minCameras(TreeNode* root, int &cameras){
        if(!root) return 1 ;

        int left = minCameras(root->left,cameras) ; 
        int right = minCameras(root->right,cameras) ; 

        if(left==0 ||right==0){ // child is in need of coverage, we have to assign root
            cameras++ ; 
            return 2 ; 
        }

        if(left==2 || right==2){ //root is covered, no need of coverage . 
            return 1 ; 
        }

        //only one case left , ie, noneed and noneed, ie, root will be in need . 
        return 0 ; 
    }

    int minCameraCover(TreeNode* root) {
        int cameras = 0 ; 
        if(minCameras(root,cameras)==0) return cameras+1 ; //if root in need , assign camera for root . 
        return cameras ; 
    }
};