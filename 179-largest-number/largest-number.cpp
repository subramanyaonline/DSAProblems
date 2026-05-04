class Solution {
public:
    bool shouldSwap(string a, string b){
        int i=0,j=0;
        int count = 0 ;
        while(count<(a.size()+b.size())){
            count++;
     
            if(i==a.size()) i=0 ;
            if(j==b.size()) j=0 ;
            if(a[i]>b[j]) return false ; //no swap , large is already in left
            else if(b[j]>a[i]) return true ;
            else { i++; j++;}
        }
        return false ;//or ture doesnot matter. 
        
    }

    string largestNumber(vector<int>& nums) {
        int n = nums.size(); 
        vector<string> vec(n) ;

        for(int i=0;i<n;i++){
            vec[i] = to_string(nums[i]) ;
        }

        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1-i;j++){
                if(shouldSwap(vec[j],vec[j+1])) swap(vec[j],vec[j+1]) ;
            }
        }

        string ans ;
        for(string ele : vec) ans += ele ;

        if(ans[0]=='0') return "0" ;  //for edge case [0,0]
        return ans ;
    }
};