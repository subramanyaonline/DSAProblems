class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n2 = costs.size(); 

        vector<vector<int>> profitSelectedA(n2,vector<int>(2)) ; //profit if i selected A //second row stores the index. 

        for(int i=0;i<n2;i++){
            profitSelectedA[i][0] = costs[i][0] - costs[i][1] ; 
            profitSelectedA[i][1] = i ; 
        }

        sort(profitSelectedA.begin(),profitSelectedA.end()) ; 

        int sum = 0 ; 
        for(int i=0;i<n2/2;i++){
            int index = profitSelectedA[i][1] ; 
            //cout<< costs[index][0]<<endl; 
            sum += costs[index][0] ; //selecing A 
        }

        for(int i=n2/2 ; i<n2 ;i++){
            int index = profitSelectedA[i][1] ; 
           // cout<< costs[index][1]<<endl;
            sum += costs[index][1] ; 
        }
        
        return sum ; 
    }
};