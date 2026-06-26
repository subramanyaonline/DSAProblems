class DSU{
private: 
    vector<int> rank ; 
    vector<int> parent ; 
public: 
    DSU(int n){
        rank.assign(n,0) ;  
        parent.assign(n,0); 
        for(int i=0;i<n;i++) parent[i] = i ; 
    }

    int findRoot(int a){
        if(parent[a]==a) return a ; 
        return parent[a] = findRoot(parent[a]) ; //path compression is like dp . 
    }

    int unionByRank(int a,int b){

        int p1 = findRoot(a);
        int p2 = findRoot(b) ; 
      
        if(p1==p2) return false ; //you can also do parent[a]==parent[b] , as path compressions has already been performed . 

        if(rank[p1]==rank[p2]){
            parent[p2] = p1 ; 
            rank[p1]++ ; 
        }else if(rank[p1]<rank[p2]){
            parent[p1] = p2 ; 
        }else{
            parent[p2] = p1 ; 
        }
        return true ;
    }
}; 

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); 
        DSU dsu(n);
        int components = n ; 

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] && dsu.unionByRank(i,j)){
                    components--; 
                }
            }
        }
        return components ; 
    }
};