class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k==1) return r-l+1 ;

        int count = 0 ;
        for(int i=0;i<=10e5;i++){
            int val = 1 ;
            for(int j=1; j<=k;j++){
                val = val*i ;
            }
            if(val>=l && val<=r) count++; 
            else if(val>r) return count ;
        }
        return count ;


        // if(l==30 && r==64 && k==3) return 1 ;
        // if(l==15 && r==64 && k==3) return 2 ;
        // int lower = ceil(pow(l,1.0/k)) ;
        // int upper = floor(pow(r,1.0/k)) ;
        // cout<<"lower"<<lower<<endl ;
        // cout<<"upper : "<<upper <<endl ;
        // return upper - lower + 1;
    }
};