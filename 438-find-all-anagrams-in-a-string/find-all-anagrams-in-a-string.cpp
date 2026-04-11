class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size()) return {} ;

        //you can also use map instead of array. i used ascii array 
        vector<int> pfreq(26,0) ;
        for(char c : p) pfreq[c-'a']++ ;

        //creating a base window in s of size k(p.size())
        vector<int> sfreq(26,0) ;
        for(int i=0;i<p.size();i++)     sfreq[s[i]-'a']++ ;

        vector<int> ans ;
        if(isequal(pfreq,sfreq)) ans.push_back(0) ;

        //starting from the next pos of base window. 
        for(int i=p.size();i<s.size();i++){
            sfreq[s[i] - 'a']++;
            sfreq[ s[i-p.size()] - 'a']-- ;
            if(isequal(pfreq,sfreq)) ans.push_back(i-p.size()+1) ;
        }

        return ans ;
    }

    bool isequal(vector<int> &pfreq, vector<int> &sfreq){
        return pfreq == sfreq ;
        // for(int i=0;i<26;i++) if(pfreq[i]!=sfreq[i]) return false ;
        // return true ;
    }
};