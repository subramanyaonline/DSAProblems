class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        int V = n ;
        vector<vector<pair<int,int>>> graph(V+1) ; 
        for(auto& road : roads){
            int node1 = road[0] ; 
            int node2 = road[1] ; 
            int cost = road[2] ; 
            graph[node1].push_back({node2,cost}) ;
            graph[node2].push_back({node1,cost}) ;  
        }
         
        vector<int> minScore(V+1,INT_MAX) ; 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq ; //score of cur path , node   
        pq.push({INT_MAX,1}) ; 

        while(!pq.empty()){
            int node = pq.top().second ; 
            int pathscore = pq.top().first ; 
            pq.pop() ; 
            if(minScore[node]<pathscore) continue ; 
           // if(node == V) return pathscore ; 

            for(auto& outgoingEdge : graph[node]){
                int to = outgoingEdge.first; 
                //cout<<outgoingEdge.second<<endl ;
                int curscore = min(outgoingEdge.second , pathscore) ; 
                //cout<<curscore<<endl ;
                
                if(minScore[to]>curscore){
                    //cout<<curscore<<" pushed"<<endl ;
                    pq.push({curscore,to}) ; 
                    minScore[to] = curscore ; 
                }
            }
        }
        return minScore[V] ; 

    }
};