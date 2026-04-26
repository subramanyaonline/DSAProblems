class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int i=0, j = 0 ;
        int mindiff = 101 ;
        while(j<nums.size() && i<nums.size()){
            while(nums[i]!=1){
                i++;
                if(i>=nums.size()) break ;
            }
            while(nums[j]!=2){
                j++;
                if(j>=nums.size()) break;
            }
            if(j>=nums.size() || i>=nums.size()) break ;
            mindiff = min(mindiff, abs(j-i));
            if(i<j)i++;
            else j++;
        }
        return mindiff==101 ? -1 : mindiff ;
    }
};