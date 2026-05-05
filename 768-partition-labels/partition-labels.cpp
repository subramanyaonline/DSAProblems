class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans ;
        unordered_map<char,int> um ; //int here keeps the last occurancee index

        for(int i=0;i<s.size();i++){
            um[s[i]] = i ;
        }

        int start = 0 ;
        int maxx = 0 ; 
        for(int i=0;i<s.size();i++){
            maxx = max(um[s[i]],maxx) ;
            if(maxx<=i){
                ans.push_back(maxx-start+1) ;
                start = maxx+1; 
                maxx = maxx + 1; 
            }
        }
        return ans ;





        // vector<int> freq(26) ;
        // for(int i=0;i<s.size();i++){
        //     freq[s[i]-'a']++;
        // }
        
        // vector<int> ans ;
        // unordered_set<char> set ; 
        // vector<int> curfreq(26) ;
        // int count = 0 ;
        // for(int i=0;i<s.size();i++){
        //     count++;
        //     set.insert(s[i]) ; 
        //     int curascii = s[i]-'a' ;
        //     curfreq[curascii]++;
        //     if(freq[curascii]==curfreq[curascii]){
        //         set.erase(s[i]) ;
        //         if(set.empty()){
        //             ans.push_back(count) ;
        //             count = 0 ;
        //         }
        //     }   
        // }
        // return ans ;
    }
};