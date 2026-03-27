class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjlist(n); 
        for(int i=0;i<edges.size();i++){
            adjlist[edges[i][0]].push_back(edges[i][1]) ;
            adjlist[edges[i][1]].push_back(edges[i][0]) ;
        }

        //dfs 
        vector<bool> visited(n,false) ;
        return dfs(adjlist,source,destination,visited); 
    }

    bool dfs(vector<vector<int>> &adjlist, int source, int destination, vector<bool> &visited){
        if(source==destination) return true ;
        visited[source] = true ;
        for(int i=0;i<adjlist[source].size();i++){
            if(visited[adjlist[source][i]]) continue ; //skip if already visited. 
            
            if(dfs(adjlist, adjlist[source][i],destination,visited)) return true ; 
            
        }
        return false ;
    }
};