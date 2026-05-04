
class Solution {
public:
    int sumOfPrimesInRange(int n) {
        
        string str = to_string(n) ;
        reverse(str.begin(),str.end());
        int r = stoi(str) ;
        int sum = 0 ;

        for(int i=min(n,r); i<=max(n,r); i++){
            if(i==1)continue ;
            int flag = 1 ;
            for(int j=2;j<i;j++){
                if(i%j==0){
                    flag = 0 ;
                    break; 
                }
            }
            if(flag) sum += i ;
        }
        return sum ;
    }
};