class KthLargest {
public:
    int kk;
    priority_queue<int, vector<int>, greater<int>> heap;
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        for(int i=0;i<nums.size();i++){
            heap.push(nums[i]);
            if(heap.size()>k) heap.pop();
        }
    }
    int add(int val) {
        heap.push(val);
        if(heap.size()>kk) heap.pop();
        return heap.top();
    }
};