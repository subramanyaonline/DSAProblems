class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int INF = 6000*100 + 1; 
        vector<int> time(n,INF) ; //visited not required as inf will be considered as not visited and any other value is considered as visited. 

        vector<vector<pair<int,int>>> adjlist(n) ; 

        for(int i=0;i<times.size();i++){
            int from = times[i][0] ; 
            int to = times[i][1] ; 
            int t = times[i][2] ; 
            adjlist[from-1].push_back({to-1,t});
        }

        queue<int> q ; //pair stores node and weight . 
        
        q.push(k-1) ;
        time[k-1] = 0 ;  

        while(!q.empty()){
            int src = q.front(); //to make the src 0 indexed. it is 1 indexed in the question . 
            q.pop(); 
             

            for(auto p : adjlist[src]){
                int dest = p.first; 
                int wOrTime = p.second; 
                if(time[src]+wOrTime  < time[dest]){
                    q.push(dest) ; 
                    time[dest] = time[src]+wOrTime  ; 
                }
            }

        }

        int maxtime = 0 ; 
        for(int i=0;i<n;i++){
            if(time[i]==INF) return -1 ; 
            maxtime = max(maxtime,time[i]) ; 
        }
        
        return maxtime ; 
    }
};