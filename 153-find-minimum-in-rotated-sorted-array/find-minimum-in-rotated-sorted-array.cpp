class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0 ; 
        int right = nums.size()- 1; 
        if(nums[left]<nums[right]) return nums[left]  ; 

        int middle ; 
        while(left<right){
            middle = (right+left)/2 ; 
            if(nums[middle]<nums[right]) right = middle ; 
            else left = middle+1 ; 
        }
        return nums[left] ; 
    }
};