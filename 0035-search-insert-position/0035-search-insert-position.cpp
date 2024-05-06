class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int s = 0;
        int e = nums.size()-1;
        
        int ans = 0;
        
        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(nums[mid] == target) return mid;
            
            if(nums[mid] < target){
                //may be the next next can be out ans
                ans = mid+1;
                //and check for correct answer
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};