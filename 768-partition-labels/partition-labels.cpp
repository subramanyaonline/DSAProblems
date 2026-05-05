class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26) ;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        
        vector<int> ans ;
        unordered_set<char> set ; 
        vector<int> curfreq(26) ;
        int count = 0 ;
        for(int i=0;i<s.size();i++){
            count++;
            set.insert(s[i]) ; 
            int curascii = s[i]-'a' ;
            curfreq[curascii]++;
            if(freq[curascii]==curfreq[curascii]){
                set.erase(s[i]) ;
                if(set.empty()){
                    ans.push_back(count) ;
                    count = 0 ;
                }
            }   
        }
        return ans ;
    }
};