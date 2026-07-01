class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0 , r= 0 , len = s.size() ; 
        unordered_map<char,int> freq ; 
        int count = 0 ; 

        while(r<len){
            freq[s[r]]++; 
            
            while(freq.size()==3){
                count += len - r ; 
                freq[s[l]]--; 
                if(freq[s[l]]==0) freq.erase(s[l]) ; 
                l++ ; 
            }

            r++ ; 
        }
        return count ; 
    }
};