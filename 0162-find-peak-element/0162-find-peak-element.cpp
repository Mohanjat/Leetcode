class Solution {
public:
    int findPeakElement(vector<int>& nums){
        int s = 1;
        int e = nums.size()-2;
        //base case
        if(nums.size() == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[nums.size()-1] > nums[nums.size()-2]) return nums.size()-1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid-1]<nums[mid] && nums[mid+1]<nums[mid]){
               return mid; 
            }
            //dekh lo bhai ya to left invalid hoga ya phir right invalid hoga
            if(nums[mid-1] < nums[mid]){
                //means deffinetaly peak lies in the right part
                //our answer lies in the right part of the array
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        } 
        return -1;
    }
};