class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        //step1-- find the pivot element
        int i = nums.size()-2;
        
        while(i>=0 && nums[i] >= nums[i+1]){
            i--;
        }
        
        //step2-- now find the just greater element to the pivot element
        if(i>=0){
             int j = nums.size()-1;
             while(j>=0 && nums[j] <= nums[i]){
                 j--;
             }
            //step3-- swap the elements
            swap(nums[i],nums[j]);
        }
        
        //step3-- pivot ke piche ke element ke elements ko reverse kr do
        reverse(nums.begin()+i+1,nums.end());
       
      
        // next_permutation(nums.begin(), nums.end()); 
    }
};