class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0 ;
        unordered_set<char> us ; 
        int l=0,r=0 ;
        while(r<s.size()){
            int curlen = r-l+1 ;
            if(!us.contains(s[r]) /*|| curlen<=maxlen*/){
                us.insert(s[r]); 
                maxlen = max(maxlen, curlen);
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