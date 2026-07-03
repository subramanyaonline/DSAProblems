class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int len = nums.size(); 
        int onesCount = 0 ; 

        for(int i=0;i<len;i++){
            if(nums[i]) onesCount++ ;
        }

        if(onesCount==0) return 0 ; 

        int minSwaps = nums.size() ; 

        int curOnes = 0 ; 
        for(int i=0;i<onesCount;i++){
            if(nums[i]) curOnes++ ; 
        }

        minSwaps = min(onesCount-curOnes,minSwaps) ; 

        int left = 1 ; 
        int right = onesCount ;
        while(left<len){
            if(nums[right]) curOnes++ ; 
            if(nums[left-1]) curOnes-- ; 
            minSwaps = min(minSwaps,onesCount-curOnes) ; 
            left++; 
            right = (right+1)%len ; 
        }

        return minSwaps ; 
    }
};