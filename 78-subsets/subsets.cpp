typedef vector<vector<int>> tdv ; //twod vector, can use macro also 

class Solution {
public:
    tdv ans ;
    tdv subsets(vector<int>& nums) {
        vector<int> curvec ;
        recursion(nums, curvec, nums.size()) ;
        return ans ;
    }

    void recursion(vector<int> &nums, vector<int> &curvec , int size ){
        if(size==0) {
            ans.push_back(curvec) ;
            return ;
        }
        recursion(nums,curvec,size-1) ;
        curvec.push_back(nums[size-1]);
        recursion(nums,curvec,size-1) ;
        curvec.pop_back() ;  //backtracking ..
    }
};