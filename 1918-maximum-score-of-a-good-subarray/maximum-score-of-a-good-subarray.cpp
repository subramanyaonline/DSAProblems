class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {

        //solving in two pionters . 

        int left = k ; 
        int right = k ;
        int score = nums[k] ;
        int minval = nums[k] ;
        int maxscore = nums[k] ;
        while(left>=0 && right<nums.size()){
            minval = min(minval,min(nums[left],nums[right]));
        maxscore = max(maxscore,(right-left+1)*minval) ; //score=(right-left+1)*minval)
            if(right==nums.size()-1) left--;
            else if(left==0) right++;
            else if(nums[left-1]<=nums[right+1]) right++; 
            else left--; //if(right>=nums.size()-1)
            //cout<<maxscore<<endl; 
        }
        return maxscore ; 


        // vector<int> leftmin(nums.size()) ;
        // vector<int> rightmin(nums.size()) ; 
        // stack<int> st ; 

        // for(int i=0;i<nums.size();++i){
        //     while(!st.empty() && nums[st.top()]>=nums[i]){
        //         st.pop();
        //     }
        //     if(!st.empty()) leftmin[i] = st.top(); 
        //     else leftmin[i] = -1 ; 
        //     st.push(i) ; 
        // }

        // st = {} ;

        // for(int i=nums.size()-1;i>=0;--i){
        //     while(!st.empty() && nums[st.top()]>nums[i]){   //only one side is considering duplicates, so that we dont coutn twice for the same subarray where there will be duplicates. 
        //         st.pop() ;
        //     }
        //     if(!st.empty()) rightmin[i] = st.top(); 
        //     else rightmin[i] = nums.size() ; 
        //     st.push(i) ; 
        // }

        // int maxscore = 0 ; 
        // for(int i=0;i<nums.size();++i){
        //     int score = (rightmin[i]-leftmin[i]-2+1) * nums[i] ;
        //     if(leftmin[i]+1<=k && rightmin[i]-1>=k)  maxscore = max(score,maxscore) ;
        // }
        // return maxscore ;
    }
};