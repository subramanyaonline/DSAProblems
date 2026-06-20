class Solution {
public:
    bool dfsIsCycle(int src, vector<vector<int>> &graph, vector<bool> &path, vector<bool> &safe){
        if(path[src]) return true ;
        if(safe[src]) return false  ; //already confirmed, memoized

        path[src] = true ; 
        for(int dest : graph[src]){
            if(dfsIsCycle(dest,graph,path,safe)){
                return true ;
            }
        }
        safe[src] = true ; 
        path[src] = false ; 
        return false ;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size(); 
        vector<bool> path(V) ; 
        vector<bool> safe(V) ; 
        vector<int> ans ; 

        for(int i=0;i<V;i++){
            dfsIsCycle(i,graph,path,safe) ; 
        }       

        for(int i=0;i<V;i++){
            if(safe[i]) ans.push_back(i) ; 
        }

        return ans ;
    }
};