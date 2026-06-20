class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans ; 
        queue<int> q ; 
        int V = graph.size(); 
        vector<int> indegree(V) ; 
        vector<vector<int>> adjlist(V); 

        for(int i=0;i<V;i++){       //here i itself is a node, which i took as destination . 
            for(int src : graph[i]){
                adjlist[src].push_back(i) ;
                indegree[i]++; 
            }
        }

        for(int i=0;i<V;i++){
            if(!indegree[i]){
                q.push(i); 
            }
        }

        while(!q.empty()){
            int src = q.front(); 
            q.pop(); 

            for(auto dest : adjlist[src]){
                if(!--indegree[dest])q.push(dest) ; 
            }
        }

        for(int i=0;i<V;i++){
            if(!indegree[i]) ans.push_back(i) ; 
        }

        return ans ;
    }
};