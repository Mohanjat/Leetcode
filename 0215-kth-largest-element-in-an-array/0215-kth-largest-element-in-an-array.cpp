class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>,greater<int> > pq;
        
        //push k elements in the min heap
        for(int i=0; i<k; i++){
            pq.push(nums[i]);
        }
        
        //now process the remaining n-k elements
        for(int i=k; i<nums.size(); i++){
            //if the curr element is greater than the top element
           // than there is a possibility that this element may be our answer
            if(nums[i] > pq.top()){
                //agr top element chota h to useko remove kr do
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};