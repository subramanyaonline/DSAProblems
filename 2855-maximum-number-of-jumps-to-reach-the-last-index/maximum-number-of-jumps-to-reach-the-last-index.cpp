class Solution {
public:
    int recursion(vector<int> &nums, vector<int> &memo, int i,int target){
        if(i==nums.size()-1) return 0 ;
        if(memo[i]!=-1) return memo[i] ;
        int maxlen = 0 ;
        for(int j=i+1;j<nums.size();j++){
            if(abs(nums[i]-nums[j])<=target) maxlen = max(maxlen,recursion(nums,memo,j,target)+1);
        }
        if(maxlen == 0) memo[i] = -10;
        else  memo[i] = maxlen ;
        return memo[i] ;
    }

    int maximumJumps(vector<int>& nums, int target) {
        vector<int> memo(nums.size(),-1) ;
        int ans = recursion(nums,memo,0,target) ;
        return ans<=0 ? -1 : ans ;

        //memo[i] = max steps to reach last index from index i . 
    }
};