class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> um ;
        for(int i=0;i<nums.size();i++){
            if(um.count(nums[i])) um[nums[i]]++ ;
            else um[nums[i]] = 1 ;
        }

        vector<int> frequencies; 
        for(pair<int,int> p : um) frequencies.push_back(p.second) ;

        priority_queue<int> pq(frequencies.begin(),frequencies.end()) ;

        int cutoff ;
        while(k>0){
            cutoff = pq.top(); 
            pq.pop() ;
            k-- ;
        }

        vector<int> ans ; 
        for(pair<int,int> p : um){
            if(p.second >= cutoff) ans.push_back(p.first) ;
        }

        return ans ;
    }
};


//takes n log n time with O(n) space. 
/*
unordered_map<int,int> um ;
        vector<int> frequencies ;
        vector<int> ans ;

        for(int i=0;i<nums.size();i++){
            if(um.count(nums[i]))um[nums[i]]++;
            else um[nums[i]] = 1;
        }        
        
        for(pair<int,int> p : um){
            frequencies.push_back(p.second) ;
        }

        sort(frequencies.begin(),frequencies.end()) ;

        int cutoff = frequencies[frequencies.size()-k] ;        

        for(pair<int,int> p : um){
            if(p.second >= cutoff) ans.push_back(p.first) ;
        }

        return ans ;


*/