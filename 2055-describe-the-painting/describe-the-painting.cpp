class Solution {
public:

    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int,long long> map ; 

        for(int i=0;i<segments.size();i++){
            int from = segments[i][0], to = segments[i][1] , color = segments[i][2] ; 
            map[from] = map[from] + color ; 
            map[to] = map[to] - color ; 
        }

        long long sum = 0 ; 
        int prevpoint = -1 ; 
        vector<vector<long long>> ans ; 
        for(auto interval : map){
            long long  color = interval.second ; 
            int endpoint = interval.first ;  
            if(sum>0){               
                ans.push_back({prevpoint,endpoint,sum}) ;   
            }
            prevpoint = endpoint ;
            sum += color ; 
        }

        return ans ; 

    }
};