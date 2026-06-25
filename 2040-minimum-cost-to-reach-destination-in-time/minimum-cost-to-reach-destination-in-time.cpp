class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {

        int V = passingFees.size(); //n 
        vector<unordered_map<int,int>> graph(V) ; 

        for(auto& edge : edges){
            int from = edge[0] ; 
            int to = edge[1] ; 
            int time = edge[2] ; 
            if(graph[from].count(to)){
                graph[from][to] = min(graph[from][to],time) ;
                graph[to][from] = min(graph[to][from],time) ; 
            }else{
                graph[from][to] = time ; 
                graph[to][from] = time ; 
            }
        }

        vector<vector<int>> mincost(V,vector<int>(maxTime+1,INT_MAX)) ; 
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq ; 
        pq.push({passingFees[0],0,0}); 
        mincost[0][0] = passingFees[0] ; //i-node, j-time  val-cost

        while(!pq.empty()){
            auto [cost,node,time] = pq.top(); 
            pq.pop(); 
            if(time==maxTime) continue ; 
            if(cost>mincost[node][time]) continue ; 
            
            for(auto& p : graph[node]){
                int destnode = p.first; 
                int desttime = p.second ; 
                int tottime = desttime+time ; 
                int totcost = cost + passingFees[destnode] ; 
                if(tottime<=maxTime && mincost[destnode][tottime]>totcost){
                    mincost[destnode][tottime] = totcost ;
                    pq.push({totcost,destnode,tottime}) ; 
                }
            }
        }

        int mindestcost = INT_MAX ; 
        for(int i=0;i<=maxTime;i++){
            mindestcost = min(mindestcost,mincost[V-1][i]) ; 
        }

        return mindestcost==INT_MAX ? -1 : mindestcost ; 

    }
};