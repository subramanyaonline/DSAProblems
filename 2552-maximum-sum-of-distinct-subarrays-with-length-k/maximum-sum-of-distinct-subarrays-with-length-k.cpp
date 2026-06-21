class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0 ;
        long long maxsum = 0 ; 
        unordered_map<int,int> occurance ;  

        for(int i=0;i<k;i++){
            sum += nums[i] ; 
            occurance[nums[i]]++; 
        }

        if(occurance.size()==k) maxsum = max(maxsum,sum) ; 

        for(int i=k;i<nums.size();i++){
            occurance[nums[i]]++; 
            sum += nums[i]; 
            sum -= nums[i-k] ; 
            occurance[nums[i-k]]--; 
            if(!occurance[nums[i-k]]) occurance.erase(nums[i-k]) ;
            if(occurance.size()==k) maxsum = max(maxsum,sum) ; 
        }

        return maxsum ; 
    }
};