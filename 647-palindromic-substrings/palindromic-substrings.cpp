class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size() ; 
        //expand from the middle 

        int noOfSubstrings = 0 ; 

        for(int i=0;i<n;i++){

            //each i index is considered as middle  

            //considering the substirng size as odd. we got a clear middle point
            int l = i , r = i ; 
            while(l>=0 && r<n && s[l]==s[r]){
                noOfSubstrings++ ; 
                l--; r++ ; 
            }

            //condidering the substring as even. we dont have a clear middle point so we are keeping the i as value of the middle 2 elements. 
            l = i ; r = i+1 ; 
            while(l>=0 && r<n && s[l]==s[r]){
                noOfSubstrings++ ; 
                l--; r++ ; 
            }
        }

        return noOfSubstrings ; 
    }
};