class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = 6000 * 100 + 1 ; 
        vector<vector<pair<int,int>>> adjlist(n) ; 
        for(int i=0;i<times.size();++i){
            adjlist[times[i][0]-1].push_back({times[i][1]-1,times[i][2]}); 
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> minTime(n,INF) ; 

        pq.push({0,k-1}) ; // pathcost , node
        minTime[k-1]=0 ; 

        while(!pq.empty()){
            int src = pq.top().second ; 
            int time = pq.top().first ; 
            pq.pop(); 
            for(auto p : adjlist[src]){
                int dest = p.first ; 
                if(time+p.second < minTime[dest]){
                    minTime[dest] = time+p.second ; 
                    pq.push({minTime[dest],dest}); 
                }
            }
        }

        int maxtime = 0 ;  
        for(int i=0;i<n;i++){
            if(minTime[i]==INF) return -1 ; 
            maxtime = max(maxtime,minTime[i]); 
        }

        return maxtime ; 

    }
};