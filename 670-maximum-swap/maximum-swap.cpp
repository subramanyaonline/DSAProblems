class Solution {
public:
    int maximumSwap(int num) {

        //find the last occurance of the digits and store them in array 
        //swap the first left digit which has a digit greater than it in the array . 

        vector<int> lastOccurance(10,-1) ;
        string s = to_string(num) ;

        for(int i=0;i<s.size();i++){
            lastOccurance[s[i]-'0'] = i ;
        }

        for(int i=0;i<s.size();i++){
            for(int j=9;j>s[i]-'0';j--){
                if(lastOccurance[j]>i){
                    swap(s[i],s[lastOccurance[j]]) ;
                    return stoi(s) ;
                }
            }
        }

        return stoi(s) ;
    }
};