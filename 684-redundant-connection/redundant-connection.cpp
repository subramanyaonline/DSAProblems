class Solution {
public:
    struct DSU{
        vector<int> parent  ; 
        vector<int> rank ; 
        public : 
        DSU(int n){
            parent.assign(n+1,0); 
            rank.assign(n+1,0) ; 
            for(int i=0;i<n+1;++i){
                parent[i] = i ; 
            }
        }

        int find(int node){
            if(parent[node]==node) return node ; 
            return parent[node] = find(parent[node]) ;
        }

        bool unite(int p1, int p2){
            int root1 = find(p1) ; 
            int root2 = find(p2) ; 
            if(root1==root2) return false ; //the current two nodes are not part of the same graph, hence we try to merge them . 

            if(rank[root1]==rank[root2]){
                rank[root1]++; 
                parent[root2] = root1 ; 
            }else if(rank[root1]>rank[root2]){
                parent[root2] = root1 ; 
            }else{
                parent[root1] = root2 ; 
            }
            return true ; 
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); 
        DSU dsu(n) ; 

        for(auto& edge : edges){
            if(!dsu.unite(edge[0],edge[1])){
                return edge ; 
            }
        }
        return {} ; 
    }
};