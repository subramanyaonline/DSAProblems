class Solution {
public:
    int minOperations(vector<int>& nums) {
        //understanding of teh problem 
        //there should be only two parts in arrays  and both should be sorted in same order . say there are 3 parts in array identified by diff>1, then impossible to sort 345 12 0 impossible
        // if only one split but both parts of arr are sorted in diff order then also impossible to sort. 3456 210  impossible
        //invalid cases, if both parts are ascending then simply leftshift
        //if descending parts then check max(rev then shift, shift then reverse)

        int n = nums.size(); 
        int split = 0 ; 
        int splitidx = 0 ;
        bool ascending = false ;
        bool descending = false ;  

        for(int i=1;i<n;i++){ 
            if(abs(nums[i]-nums[i-1])>1){
                split++; 
                splitidx = i-1 ; 
            }
            //to check for both asc and dsc parts in the array apart from splitidx.
            if(nums[i-1]>nums[i] && abs(nums[i-1]-nums[i])==1) descending = true ;
            if(nums[i-1]<nums[i] && abs(nums[i-1]-nums[i])==1) ascending = true ;
        }


        if(n==1) return 0 ;
        if(split>1) return -1 ;
        if(ascending && descending) return -1 ; 
        if(split==0 && nums[0]<nums[1]) return 0 ;//monotoinic ascending
        if(split==0 && nums[0]>nums[1]) return 1 ; //monotonic descending
         

        int firstPartElements = splitidx+1 ;
        int secondPartElements = n - firstPartElements ; 

        if(ascending){
            return min(firstPartElements,1+secondPartElements+1) ;
        }else if(descending){
            return min(firstPartElements+1, 1+secondPartElements);
        }

        return 0 ; 
    }
};