class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, totsum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i] ;
        }
        for(int i=0;i<=nums.size();i++){
            totsum += i ;
        }
        return totsum - sum ;
    }
};

//many aproaches to solve this problem , using xor or using sum 