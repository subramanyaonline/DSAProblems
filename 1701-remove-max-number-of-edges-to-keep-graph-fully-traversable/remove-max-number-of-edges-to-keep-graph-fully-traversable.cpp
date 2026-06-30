class Solution {
public:
    struct DSU{
        vector<int> rank; 
        vector<int> parent ; 
        DSU(int n){
            rank.resize(n+1,0) ; 
            parent.resize(n+1,0); for(int i=0;i<=n;++i) parent[i] = i ; 
        }

        int findParent(int node){
            if(parent[node]==node) return node ; 
            return parent[node] = findParent(parent[node]) ; 
        }

        bool unionByRank(int node1, int node2){
            int root1 = findParent(node1) ; 
            int root2 = findParent(node2) ; 
            if(root1==root2) return false ; 

            if(rank[root1]==rank[root2]){
                parent[root2] = root1 ; 
                ++rank[root1] ; 
            }else if(rank[root1]>rank[root2]){
                parent[root2] = root1 ; 
            }else{
                parent[root1] = root2 ; 
            }
            return true ;
        }
    }; 

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsuA(n) ; 
        DSU dsuB(n) ; 
        
        int componentsA = n , componentsB = n ;  
        int extraEdgesA = 0 , extraEdgesB = 0 ; 
        int commonExtraEdge = 0 ; 


        for(auto &edge : edges){
            if(edge[0]==3){
                int node1 = edge[1] ; 
                int node2 = edge[2] ; 
                int type = edge[0] ; 
                if(type==1){
                    if(dsuA.unionByRank(node1,node2)) componentsA-- ; 
                    else extraEdgesA ++ ; 
                }else if(type==2){
                    if(dsuB.unionByRank(node1,node2)) componentsB-- ; 
                    else extraEdgesB ++; 
                }else{
                    bool connectedA = false , connectedB = false ; 
                    if(dsuA.unionByRank(node1,node2)) componentsA-- ; 
                    else { extraEdgesA ++ ; connectedA = true ; } 
                    if(dsuB.unionByRank(node1,node2)) componentsB-- ; 
                    else { extraEdgesB ++; connectedB = true ; }
                    if(connectedA && connectedB) commonExtraEdge++ ; 
                }
            }
        }

        for(auto &edge : edges){
            if(edge[0]!=3){
                int node1 = edge[1] ; 
                int node2 = edge[2] ; 
                int type = edge[0] ; 
                if(type==1){
                    if(dsuA.unionByRank(node1,node2)) componentsA-- ; 
                    else extraEdgesA ++ ; 
                }else if(type==2){
                    if(dsuB.unionByRank(node1,node2)) componentsB-- ; 
                    else extraEdgesB ++; 
                }
                //type3 has been processed earlier. 
            }
        }

        if(componentsA!=1 || componentsB!=1) return -1 ; 
        else return extraEdgesA + extraEdgesB - commonExtraEdge ; 
    }
};