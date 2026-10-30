class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //can be done using hashset and map in two ways , 
        //first way -> if the cur ele is already in set , remove till that element is gone, then add curele.
        //second way -> cur ele moves one by one , increasing the frequency in hashamap , each time ,
        // for each cur ele , we check if freq is > 1, if yes , hten we remove till it becocmes =1 . 

        //but this can be done in more interesting way , whichis using lastoccurnace index value . 

        unordered_map<char,int> lastOccurance  ; 
        int maxlen = 0 ; 
        int left = -1 ; 

        for(int i=0;i<s.size();++i){
            if(lastOccurance.count(s[i])) left = max(left,lastOccurance[s[i]]) ; 
            lastOccurance[s[i]] = i ; 
            int curlen = i-left ; 
            maxlen = max(maxlen,curlen) ; 
        }


        return maxlen ; 
    }
};