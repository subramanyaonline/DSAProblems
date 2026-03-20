class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() ;
        int sum = 0, totsum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i] ;
        }
        totsum = n*(n+1)/2;
        return totsum - sum ;
    }
};

//many aproaches to solve this problem , using xor or using sum 