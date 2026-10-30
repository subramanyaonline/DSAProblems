class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        
        vector<vector<pair<int,int>>> graph(n); 

        for(int i=0;i<edges.size();++i){
            int from = edges[i][0] ; 
            int to = edges[i][1] ; 
            int w = edges[i][2] ; 

            graph[from].push_back({w,to});   //w,to
        }

        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq ; //weight , consecutive numers , to 

        vector<vector<int>> minweight(n,vector<int>(k+1,INT_MAX)) ;   //to,k  - consecutive elements 
        minweight[0][1] = 0 ; 
        pq.push({0,1,0}) ;              ////weight , consecutive numers ,to 
        int finalans = INT_MAX ; 

        while(!pq.empty()){
            int prevweight = pq.top()[0] ;                     
            int K = pq.top()[1] ;
            int from = pq.top()[2] ;  
            pq.pop() ; 

            for(pair<int,int> p : graph[from]){
                int to = p.second ; 
                int w = p.first ; 

                int curweight = w + prevweight ; 
                int curK = labels[from]==labels[to] ? K+1 : 1 ; 
                if(curK > k) continue ; 

                if(minweight[to][curK] > curweight){
                    minweight[to][curK] = curweight ; 
                    pq.push({curweight,curK,to}) ; 
                    
                    if(to==n-1) finalans = min(finalans,curweight) ; 
                }
                
            }
        }

        //edge case , i failed here ,
        if(n==1) return 0 ; 

        if(finalans == INT_MAX) return -1 ; 
        return finalans ; 

    }
};