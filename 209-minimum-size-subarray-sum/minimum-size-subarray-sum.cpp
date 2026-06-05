class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen = 10e5 + 1 ; 
        int sum = 0 ; 
        int i = 0 ; 
        int j = 0; 
        while(j<nums.size()){
            sum += nums[j] ; 
            while(sum>=target){
                minlen = min(minlen,j-i+1) ;
                sum -= nums[i];                 
                i++;
            }
            j++; 
        }
        return minlen>10e5 ? 0 : minlen ;
    }
};