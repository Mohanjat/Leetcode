class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kadane's algo
        int maxSum = INT_MIN;
        int sum = 0;
        
        for(int i=0; i<nums.size(); i++){
            //add the curr element
            sum += nums[i];
            
            //update the max sum 
            maxSum = max(maxSum,sum);
            
            //check kr lo khi sum negative m to nhi h
            if(sum < 0) sum = 0;
        }
         
        return maxSum;
    }
};