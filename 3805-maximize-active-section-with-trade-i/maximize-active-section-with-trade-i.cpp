class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size() ; 
        int totalones = 0 ; 
        for(int i=0;i<n;++i) if(s[i]=='1')   totalones++ ; 

        int k ; 
        for(k=0;k<n && s[k]=='1';++k) ; 
        if(k==n) return totalones ; 

        char prev = s[k] ; 

        vector<int> splits; 
        int count = 1 ; 

        for(int i=k+1;i<n;i++){
            if(s[i]==prev) count++ ;
            else {
                splits.push_back(count) ; 
                prev = s[i] ; 
                count = 1 ; 
            }
        }
        splits.push_back(count) ; 

        int maxgain = 0 ; 

        for(int i=2;i<splits.size();i+=2){
            int curgain = splits[i]+splits[i-2] ; 
            maxgain = max(maxgain,curgain) ; 
        }
        
        //for(int i=0;i<splits.size();++i) cout<<splits[i]<<" " ; 

        return maxgain + totalones ; 
    }
};