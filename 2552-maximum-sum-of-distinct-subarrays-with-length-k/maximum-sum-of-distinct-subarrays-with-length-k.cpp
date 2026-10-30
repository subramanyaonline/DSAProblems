class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxsubarraysum = 0 ; 
        unordered_map<int,int> map ; 
        long long cursum = 0 ; 

        for(int i=0;i<k;++i){
            map[nums[i]]++ ; 
            cursum += nums[i] ; 
        }

        if(map.size()==k) maxsubarraysum = max(maxsubarraysum, cursum ) ; 

        for(int i=k;i<nums.size();++i){
            map[nums[i-k]]-- ; 
            if(map[nums[i-k]]==0) map.erase(nums[i-k]) ; 

            map[nums[i]]++ ; 
            cursum = cursum - nums[i-k] + nums[i] ; 
            if(map.size()==k) maxsubarraysum = max(maxsubarraysum, cursum) ; 
        }

        return maxsubarraysum ; 
    }
};