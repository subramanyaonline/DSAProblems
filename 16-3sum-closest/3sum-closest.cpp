class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end()) ;

        //int closestSum = 1000000001 ; 
        int closestSum = nums[0]+nums[1]+nums[2] ;
        //int max might overflow when closestSum-target(if target is negative .)
        //or better option is just initialize with first three elements sum given nums has minimum 3 elements . 

        for(int i=0;i<nums.size()-2;i++){

            int left = i+1 , right = nums.size()-1 ;
            int localTarget = target - nums[i] ;

            while(left<right){  //if i=n, j=n-1, then overflow, infinite loop . 

                int currentSum = nums[i]+nums[left]+nums[right];

                if(abs(target-currentSum)<abs(closestSum-target)){
                    closestSum = currentSum ;
                }

                if(currentSum < target) left++;
                else if(currentSum > target) right--;
                else return currentSum;
                
                // if(nums[left]+nums[right]<localTarget) left++;
                // else if(nums[left]+nums[right]>localTarget) right--;
                // else return closestSum = currentSum ;
            }
        }
        return closestSum ;
    }
};