class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0 ;
        unordered_set<char> us ; 
        int l=0,r=0 ;
        while(r<s.size()){
            if(!us.contains(s[r])){
                us.insert(s[r]); 
                maxlen = max(maxlen, r-l+1);
                r++ ;              
            }
            else{
                us.erase(s[l]);
                l++;
            }
        }
        return maxlen ;
    }
};