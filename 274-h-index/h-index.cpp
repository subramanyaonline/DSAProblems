class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size() ; 
        sort(citations.begin(),citations.end()) ; 
        
        for(int i=0; i<n; ++i){
            int hindex = n-i ; //count
            if(hindex<=citations[i]) return hindex ; 
        }
        return 0 ; 
    }
};