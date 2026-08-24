class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //0 to n -> sum is n*(n+1)/2 ; 

        int observedsum = 0 ; 
        int n = nums.size() ; 
        for(int num : nums){
            observedsum += num ; 
        }

        int expectedsum = (n*(n+1))/2 ; 

        return expectedsum - observedsum ; 
    }
};