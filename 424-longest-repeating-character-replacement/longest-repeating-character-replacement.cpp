class Solution {
public:
    int characterReplacement(string s, int k) {
        //After seeing the solution, i got to know that only maxfreq matters and windowlen - maxfreq = noOfLettersToChange. if it is greater than k, just reduce the window size 
        //no need to recalculate the maxfreq while reducing the window because only a maxfreq higher than previous one will give us better answer than what we have . 

        //there can only be one letter in whole substring, so we are making replacing every other letter , which is given by substrlen - maxfreq = replacingletters. 

        int maxlen = 0 , i = 0 , maxfreq = 0 ; 
        vector<int> freq(26) ;

        for(int j=0;j<s.size();j++){
            freq[s[j]-'A']++;
            maxfreq = max(maxfreq,freq[s[j]-'A']) ;
            
            int replacingchars = j-i+1 - maxfreq ; 
            while(j-i+1 - maxfreq > k){
                freq[s[i]-'A']--;
                i++;
            }
            maxlen = max(maxlen,j-i+1) ;
        }
        
        return maxlen ;
    }
};