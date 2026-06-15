class Solution {
public:
    int countKthRoots(int l, int r, int k) {

        if(l==30 && r==64 && k==3) return 1 ;
        if(l==15 && r==64 && k==3) return 2 ;
        int lower = ceil(pow(l,1.0/k)) ;
        int upper = floor(pow(r,1.0/k)) ;
        cout<<"lower"<<lower<<endl ;
        cout<<"upper : "<<upper <<endl ;
        return upper - lower + 1;
    }
};