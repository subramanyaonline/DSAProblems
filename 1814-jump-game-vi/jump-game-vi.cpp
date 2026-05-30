class Solution {
public:

//lazy deletion using pq , um , results in O(nlogk) //logk to insert one ele , while max size will be k of pq , um doesnot count as it takes constant time . 

//monotonic dequeue, used O(n) space and time, which is optimal here. 

    int maxResult(vector<int> &nums, int k){
        vector<int> dp(nums.size()) ;
        deque<int> q ;      //will store only indices in monotonic queue . 
        q.push_back(0) ;         
        dp[0] = nums[0] ;   //dp[i] = max sum possible to reach index i . 
        
        for(int i=1;i<nums.size();i++){
            //removing the left edge of the window
            if(q.front()==i-k-1) q.pop_front() ; 
            dp[i] = nums[i] + dp[q.front()]; 
            while(!q.empty() && (dp[q.back()] <= dp[i])){
                q.pop_back() ;
            }
            q.push_back(i) ;
        }

        return dp[nums.size()-1] ; 
    }
};


/*
int maxResult(vector<int>& nums, int k) {
        //linear dp 
        //dp[i] = maxsum possible to reach i from 0 pos. 
        
        vector<int> dp(nums.size(),0) ;
        unordered_map<int,int> um ;  
        //to store the dp[i] which are not int the current window. since we cannot directly remove the desired item in pq, we store it and remove when it reaches the top, and also remove it from hashmap . 
        priority_queue<int> pq ;

        dp[0] = nums[0] ; 
        pq.push(dp[0]) ;

        
        for(int i=1;i<nums.size();i++){

            //reving the left edge of the window 
            if(i-k-1 >= 0){
                if(um.count(dp[i-k-1])) um[dp[i-k-1]]++; 
                else um[dp[i-k-1]] = 1 ;
            }

            //removing top if it is in hashmap , ie, they have to be deleted 
            while(um.count(pq.top())){   //same sum multi dp[i] may exist
                if(um[pq.top()]==1) um.erase(pq.top()) ;
                else um[pq.top()]-- ;
                pq.pop() ; // i did not use !pq.empty() because min value of k is 1, so there will always be atleast one element in the pq. 
            }

            dp[i] = nums[i] + pq.top() ; 
            pq.push(dp[i]) ;
        }      
        return dp[nums.size()-1] ;    
    }
*/


//the below solution works, but TLE, also see the 
        //so thought of trying
        /*
        for(int i=1;i<nums.size();i++){

            dp[i] = dp[i-1]+nums[i] ;       //wihtout this, int_min, 0 will not work as negative integers are there. 
            //So learning is, always initialize with default possible value, first case. 

            for(int j=i-1;j>=max(0,i-k);j--){
                dp[i] = max(dp[i],dp[j]+nums[i]) ;
            }   

        } 
        */