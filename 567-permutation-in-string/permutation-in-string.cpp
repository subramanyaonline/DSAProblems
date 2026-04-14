class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false ;

        vector<int> freq(26,0) ;      //freq of vector 1 
        vector<int> v(26,0) ;       //freq of sliding window

        for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']++;
            v[s2[i]-'a']++;
        }

        if(v==freq) return true ;

        for(int i=s1.size();i<s2.size();i++){
            v[s2[i]-'a']++ ;
            v[s2[i-s1.size()]-'a']-- ;
            bool isequal = true ;
            for(int i=0;i<26;i++){
                if(v[i]!=freq[i]) isequal = false ;
            }
            if(isequal) return true ;
        }
        return false ;
    }
};