class Solution {
public:
    int minDifference(vector<int>& nums) {
        //approach ##1 using sorting 
        //4 possibalities only
//min of (nums[n-4] - nums[0], nums[n-1]-nums[3], nums[n-3]-nums[1],nums[n-2]-nums[2])
        
        sort(nums.begin(),nums.end());
        
        if(nums.size() < 5)  return 0;
        
        int n = nums.size();
        
        int ans1 = nums[n-4] - nums[0];
        int ans2 = nums[n-1] - nums[3];
        int ans3 = nums[n-3] - nums[1];
        int ans4 = nums[n-2] - nums[2];
        
        return min(ans1,min(ans2,min(ans3,ans4)));
        
    }
};