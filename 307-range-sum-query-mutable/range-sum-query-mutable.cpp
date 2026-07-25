class NumArray {
    vector<int> tree ; 
    int n ; 

    void build(vector<int> &nums, int start, int end, int node){
        if(start==end){
            tree[node] = nums[end] ; 
            return ;
        }
        int mid = start + (end-start)/2 ; 
        build(nums,start,mid,node*2+1) ; 
        build(nums,mid+1,end,node*2+2) ;
        tree[node] = tree[node*2+1] + tree[node*2+2] ; 
        return ;
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size() ; 
        tree.resize(4*n) ;
        build(nums,0,n-1,0) ;
    }
    
    void update(int index, int val) {
        update(index,val,0,n-1,0) ; //index,val,start,end,node(curnode in tree)
    }
    
    void update(int index, int val , int start , int end, int node){
        if(start==end){
            tree[node] = val ; 
            return ; 
        }
        int mid = start+(end-start)/2 ; 
        if(start<=index && index<=mid) update(index,val,start,mid,2*node+1) ; 
        else update(index,val,mid+1,end,2*node+2) ;
        tree[node] = tree[node*2+1] + tree[node*2+2] ; 
    }

    int sumRange(int left, int right) {
        return sumRange(tree,left,right,0,n-1,0)     ; 
    }

    int sumRange(vector<int> &tree, int qleft, int qright , int start, int end,int node){
        //complete overlap 
        if(qleft <= start && qright >= end)  return tree[node] ; 
        //no overlap 
        else if(qleft > end || qright < start) return 0 ; 
        
        //partial overlap 
        int mid = start + (end-start)/2 ; 
        return sumRange(tree,qleft,qright,start,mid,node*2+1) + sumRange(tree,qleft,qright,mid+1,end,node*2+2) ; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */