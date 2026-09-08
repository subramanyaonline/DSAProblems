class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxlen = 1 ; int curlen = 1 ; 
        for(int i=1;i<nums.size();++i){
            if(nums[i]<=nums[i-1])    curlen = 1 ; 
            else    curlen++ ; 
            maxlen = max(maxlen,curlen) ; 
        }
        return maxlen ; 
    }
};