class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        vector<vector<pair<int,double>>> adjlist(n) ; 
        for(int i=0;i<edges.size();i++){
            adjlist[edges[i][0]].push_back({edges[i][1],succProb[i]}) ; 
            adjlist[edges[i][1]].push_back({edges[i][0],succProb[i]}) ; 
        }

        vector<double> bestProb(n,0.0) ; //-1 means visited , if 0 kept , then some answer might be 0 and unvisited also 0 , so we will end up calculating agin, infinite loop . --not sure of this theory, but -1 is good . 
        //i changed this to 0 , guessing we will push only if we get >0 , so no infinite loops. 
        priority_queue<pair<double,int>> pq ; 

        pq.push({1.0,start_node}) ; 
        bestProb[start_node] = 1; 

        while(!pq.empty()){
            int from = pq.top().second ; 
            double curprob = pq.top().first ; 
            pq.pop(); 
            //cout<<from<<" " ; 
            if(bestProb[from]>curprob) continue ; 
            
            for(pair<int,double> p : adjlist[from]){
                int to = p.first ; 
                if(bestProb[from] * p.second > bestProb[to]){
                    bestProb[to] = bestProb[from]* p.second ; 
                    pq.push({bestProb[to],to}); 
                }
            }
        }
        //for(int i : bestProb) cout<<i<<" " ; 
        return bestProb[end_node] ; 

    }
};