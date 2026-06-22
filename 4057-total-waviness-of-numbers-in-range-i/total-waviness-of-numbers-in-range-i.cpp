class Solution {
public:
    int waviness(int n){
        string s = to_string(n) ; 

        if(s.size()<3) return 0 ; 

        int i = 0 ;
        int j = 2 ; 
        int waviness = 0 ; 
        //peak  

        while(j<s.size()){
            if(s[j-1]<s[j] && s[j-1]<s[i]) waviness++; 
            else if(s[j-1]>s[j] && s[j-1]>s[i]) waviness++; 
            i++; j++; 
        }

        return waviness ; 
    }

    int totalWaviness(int num1, int num2) {
        int noOfWaviness = 0 ; 
        for(int i=num1; i<=num2; i++){
            noOfWaviness += waviness(i) ; 
        }
        return noOfWaviness ; 
    }
};