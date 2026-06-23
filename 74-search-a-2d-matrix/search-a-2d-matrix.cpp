class Solution {
public:
    bool findInrow(vector<int> &row,int target){
        int l = 0 ; int r = row.size()-1 ; 
        int middle ; 

        while(l<=r){
            cout<<"inner"<<endl ; 
            middle = (r+l)/2 ; 
            if(row[middle]==target)  return true ; 
            else if(row[middle]<target) l = middle+1 ; 
            else r = middle -1 ; 
        }
        return false ; 
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int lrow = 0 ; 
        int rrow = matrix.size()-1 ; 
        int middlerow ; 

        while(lrow<rrow){
            cout<<"while"<<endl ;
            middlerow = (rrow + lrow)/2 ; 
            if(matrix[middlerow][0]==target)return true ; //also works fine actualy
            else if(matrix[middlerow][0]<target && matrix[middlerow][matrix[0].size()-1]>=target) rrow = middlerow  ; 
            else if(matrix[middlerow][0]<target && matrix[middlerow][matrix[0].size()-1]<target) lrow  = middlerow + 1 ; 
            else rrow = middlerow - 1; 
        }

        if(lrow==rrow) return findInrow(matrix[lrow],target);

        return false ; 
    }
};