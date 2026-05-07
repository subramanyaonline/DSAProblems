class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] ;  for(int i=0;i<26;i++) freq[i]=0 ;
        for(int ele : s) freq[ele-'a']++;

        string ans ; 
        char prevchar = ' ';     //previously pushed/used char to the string 
        int maxfreq  ;
        char maxchar = ' '; //char that has the max frequency 

        for(int i=0;i<s.size();i++){
            maxfreq = 0 ;
            maxchar = prevchar ;
            //could have priority queue instead of this, to get the optmial solution
            for(int j=0;j<26;j++){
                if(maxfreq<freq[j] && (j+'a') != prevchar){
                    maxfreq = freq[j] ;
                    maxchar = j + 'a';
                }
            }
            if(prevchar == maxchar) return "";
            ans.push_back(maxchar) ;
            freq[maxchar-'a']--;
            prevchar = maxchar ;
        }
        return ans ;
    }
};