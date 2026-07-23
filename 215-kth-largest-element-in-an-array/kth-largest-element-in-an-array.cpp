class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0 , right = nums.size()-1 ; 
        int targetpos = k-1 ; 
        
        while(left<=right){ //because we are returning inside while, <=, only breaks once found the pos which lies in the range left-right for sure . 
            
            //to make the worst case very highly unlikely . 
            int pivotIndex = left + rand() % (right - left + 1);
            swap(nums[pivotIndex], nums[right]);
            int pivot = nums[right];

            //int pivot = nums[right] ; 
            int p = left ; 

            for(int i=left;i<right;i++){ //we are finding the correct postion for pivot. 
                if(nums[i]>pivot){  //if we found any smaller ele than pivot .
                    swap(nums[i],nums[p]); 
                    p++ ; 
                }
            }

            swap(nums[p],nums[right]) ; //giving pivot the correct postion which is p 

            if(p==targetpos){ //target = k-1 ; 0 indexed right . so 
                return nums[p] ; 
            }else if(p<targetpos){  //target pos is in the right part 
                left = p+1 ; 
            }else{  //target pos is in the left part .
                right = p-1 ; 
            }
        }
        return -1 ; 
    }
};