class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> um ;
        um[0] = 1 ;
        int sum=0,count=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i] ;
            if(um.count(sum-goal)) count+=um[sum-goal];
            if(um.count(sum))um[sum]++;
            else um[sum]=1 ;
        }

        return count ;








        // unordered_map<int,int> um ;
        // um[0] = 1 ;
        // int cursum = 0 ;
        // int count = 0 ;
        // bool flag = 0 ;
        // for(int i=0;i<nums.size();i++){
        //     cursum += nums[i] ;
        //     if(i==1 || cursum>0) flag = 1 ;
        //     if(um.count(cursum) && flag) um[cursum]++;
        //     else um[cursum] = 1 ;
        //     //if(cursum==goal) count++ ;
        //     if(um.count(cursum-goal)) count+= um[cursum-goal] ;
        // }
        // return count ;


        // // int l = 0 , r= 0 ;
        // // int sum = 0 ;
        // // int count = 0  ;
        // // while(r<nums.size()){
        // //     sum += nums[r] ;
        // //     if(sum<goal){
        // //         r++;
        // //     }else if(sum>goal){
        // //         while(sum>=goal){   // i need to make sum less than goal . 
        // //             sum -= nums[l] ;
        // //             if(sum==goal) count++ ;
        // //             l++ ;
        // //         }
        // //     }
        // //     else{
        // //         count++; 
        // //         r++; 
        // //     }
        // // }

        // // return count ;
    }
};