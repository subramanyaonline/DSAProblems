class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0 ;
        double maxavg = 0 ;
        //creating base window of size k 
        for(int i=0;i<k;i++){
            sum += nums[i] ;
        }
        maxavg = sum/(double)k ;
        for(int i=k;i<nums.size();i++){
            sum = sum - nums[i-k] + nums[i] ;
            maxavg = max(maxavg , sum/(double)k) ;
        }
        return maxavg ;
    }
};