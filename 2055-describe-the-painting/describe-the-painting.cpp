class Solution {
public:

    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int n = 0; 
        for(int i=0;i<segments.size();i++){
            n = max(n,segments[i][1]); 
        }

        vector<long long > diffarr(n+1) ; 
        vector<bool> ends(n+1) ; 
        
        for(int i=0 ; i<segments.size();i++){
            int from = segments[i][0] ; 
            int to = segments[i][1] ; 
            int color = segments[i][2] ; 
            diffarr[from] = diffarr[from] + color ;
            ends[from] = ends[to] = true ; 
            diffarr[to] = diffarr[to] - color ;  
        }

        long long prevcolor = diffarr[0] ; 
        int segment1 = 0 ; //start segment 
        vector<vector<long long>> ans ; 
        for(int i=1;i<=n;i++){
            diffarr[i] = diffarr[i-1] + diffarr[i] ; 
            long long curcolor = diffarr[i] ; 
                 
            if(ends[i] && prevcolor!=0){
                ans.push_back({segment1,i,prevcolor}); 
                segment1 = i ; 
                prevcolor = diffarr[i] ; 
            }else if(ends[i] && prevcolor==0){
                segment1 = i ; 
                prevcolor = diffarr[i] ; 
            }

        }

        //if(prevcolor!=0) ans.push_back({segment1,n,prevcolor}); 

        return ans ;
    }
};