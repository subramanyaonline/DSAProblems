class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        // we have to find the subarray which has highest max-min val . 
        int maxele = nums[0]; 
        int minele = nums[0]; 
        for(int i=1;i<nums.size();i++){
            minele = min(minele,nums[i]) ; 
            maxele = max(maxele,nums[i]) ; 
        }
        return (maxele-minele)*1L*k ;
    }
};