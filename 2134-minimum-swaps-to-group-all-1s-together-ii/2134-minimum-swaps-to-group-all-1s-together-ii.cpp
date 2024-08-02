class Solution {
public:
    int minSwaps(vector<int>& nums){
        
        int ones = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1) ones++;
        }
        
        int i = 0;
        int j = 0;
        
        int minSwap = 0;
        int zeros = 0;
        
        while(j<ones){
            if(nums[j] == 0) zeros++;
            j++;
        }
        
        minSwap = zeros;
        
        while(j<2*nums.size()){
            if(nums[i%nums.size()] == 0){
                zeros--;
            }
            i++;
            if(nums[j%nums.size()] == 0){
                zeros++;
            }
            j++;
            
            minSwap = min(minSwap,zeros);
            
        }
    
        return minSwap;
        
    }
};