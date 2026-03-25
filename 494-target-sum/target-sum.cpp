

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return recursion(nums,target,nums.size()) ;
    }
    int recursion(vector<int> &nums, int target , int size){
        if(target==0 && size==0) return 1 ;
        if(size==0) return 0 ;
        return recursion(nums,target-nums[size-1],size-1) + recursion(nums,target+nums[size-1] , size-1 ) ;
    }
};

