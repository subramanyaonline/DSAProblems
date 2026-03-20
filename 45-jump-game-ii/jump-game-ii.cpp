class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,100000);
        dp[n-1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i ; j<=i+nums[i] ; j++){
                if(j>=n) break ;
                dp[i] = min(dp[j]+1, dp[i]) ;
            }
        }
        return dp[0] ;
    }
};