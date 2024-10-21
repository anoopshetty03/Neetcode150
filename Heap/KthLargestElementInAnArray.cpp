// https://leetcode.com/problems/kth-largest-element-in-an-array/

// Using Max Heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>maxHeap;
        for(int i=0;i<nums.size();i++){
            maxHeap.push(nums[i]);
        }
        int f = k-1;
        while(f>0){
            maxHeap.pop();
            f--;
        }
        return maxHeap.top();
    }
};

// Using Min Heap
class Solution {
public:
     int findKthLargest(vector<int>& nums, int k) {
         priority_queue<int, vector<int>, greater<int>> pq;
         for (int i = 0; i < nums.size(); i++) {
             pq.push(nums[i]);
             if (pq.size() > k) {
                 pq.pop();
             }
         }
         return pq.top();
    }
};