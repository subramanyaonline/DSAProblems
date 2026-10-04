class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //so this is greedy . 
        int sum = 0 ; 
        int maxsubarraysum = INT_MIN ; 
        for(int i=0;i<nums.size();++i){
            sum += nums[i] ; 
            maxsubarraysum = max(maxsubarraysum,sum) ; 
            sum = sum > 0 ? sum : 0 ; 
        }
        return maxsubarraysum ; 
    }
};