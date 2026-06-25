class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq ; 
        vector<vector<int>> minCost(n,vector<int>(k+2,INT_MAX)) ; 
        vector<vector<pair<int,int>>> graph(n) ; 
        
        for(int i=0;i<flights.size();i++){
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]}); 
        }

        pq.push({0,src,0}) ; //cost, source, stops till now. , max stops will be k+2 
        minCost[src][0] = 0 ; 

        while(!pq.empty()){
            auto [cost,src,stops] = pq.top() ; 
            pq.pop(); 
            if(stops==k+1) continue ; 
            if(minCost[src][stops]<cost) continue ; 

            for(auto p : graph[src]){
                int curcost = p.second ; 
                int dest = p.first ; 
                if(minCost[dest][stops+1]>cost+curcost){
                    minCost[dest][stops+1] = cost+curcost ; 
                    pq.push({minCost[dest][stops+1],dest,stops+1}) ; 
                }
            }
        }
        int minn = INT_MAX ; 
        for(int i=0;i<k+2;i++){
            minn = min(minCost[dst][i],minn) ; 
        }

        return minn==INT_MAX ? -1 : minn ;
    }
};