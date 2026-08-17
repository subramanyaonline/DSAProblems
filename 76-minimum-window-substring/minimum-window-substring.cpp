class Solution {
public:
    bool isEqual(vector<int> &tfreq, vector<int> &sfreq){
        for(int i=0;i<58;++i){
            if(tfreq[i] > sfreq[i]) return false ;
        }
        return true ;
    }

    string minWindow(string s, string t) {
        vector<int> tfreq(58) ; 
        vector<int> sfreq(58) ;
        int len = INT_MAX , start = 0 ;  
        
        int m = s.size(), n = t.size() ; 
        int j = 0 , i = 0 ; 

        for(int i=0;i<n;++i){
            tfreq[t[i]-'A']++ ; 
        }

        for(;j<m;j++){
            sfreq[s[j]-'A']++; 

            while(isEqual(tfreq,sfreq)){ //no need of i<=j, cause that never happens as t atleast has one element in it . so i never crosses j actually 
                if(len>j-i+1){
                    start = i ; 
                    len = j-i+1 ; 
                }
                sfreq[s[i]-'A']--; 
                i++; 
            }
        }

        if(len==INT_MAX) return "" ; 
        return s.substr(start,len) ; 

    }
};