class NumArray {
private:
    vector<int> seg_tree;
    int n;

    void buildTree(vector<int>&nums, int node, int left, int right){
        if(left == right){
            seg_tree[node] = nums[left];
            return;
        }
        int mid = (left + right)/2;
        buildTree(nums, node*2, left, mid);
        buildTree(nums, node*2 + 1, mid + 1, right);
        seg_tree[node] = seg_tree[node*2] + seg_tree[node*2 + 1];

        return;
    }

    int query(int node, int l, int r, int ql, int qr){
        if(qr < l || ql > r) return 0;
        if(ql <= l && qr >= r) return seg_tree[node];
        int mid = (l + r) /2 ;
        return query(node*2, l, mid, ql, qr) + query(node*2 + 1, mid + 1, r, ql, qr);
    }

    void update_seg(int node, int l, int r, int index, int val){
        if(l == r){
            seg_tree[node] = val;
            return;
        }
        int mid = (l + r) /2;
        if(index > mid){
            update_seg(node*2 + 1, mid + 1, r, index, val);
        }else{
            update_seg(node*2, l, mid, index, val);
        }
        
        seg_tree[node] = seg_tree[node*2] + seg_tree[node*2 + 1];
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg_tree.resize(4*n);
        buildTree(nums, 1, 0, n-1);
    }
    
    void update(int index, int val) {
        update_seg(1, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(1, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */