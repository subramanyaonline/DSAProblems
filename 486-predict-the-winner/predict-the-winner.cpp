class Solution {
public:
    bool recursion(vector<int> &nums, int score1, int score2 , int i , int j,bool turn){
        if(i>j)return score1>=score2 ; 
        bool a,b ; 
        if(turn){
            a = recursion(nums,score1+nums[i],score2,i+1,j,false) ; 
            b = recursion(nums,score1+nums[j],score2,i,j-1,false) ; 
        }else{
            a = recursion(nums,score1,score2+nums[i],i+1,j,true) ; 
            b = recursion(nums,score1,score2+nums[j],i,j-1,true) ; 
        }
        if(turn) return a||b ; 
        return a&&b ;
    }
    bool predictTheWinner(vector<int>& nums) {
        return recursion(nums,0,0,0,nums.size()-1,true) ; 
    }
};