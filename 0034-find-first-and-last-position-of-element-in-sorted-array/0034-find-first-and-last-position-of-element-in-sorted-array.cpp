class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int s = 0;
        int e = nums.size()-1;
        
        vector<int> ans(2,-1);
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid] == target){
                //check for first and last possition
                int i = mid;
                int j = mid;
                while(i>=0 && nums[i] == target){
                    ans[0] = i;
                    i--;
                }
                while(j<nums.size() && nums[j] == target){
                    ans[1] = j;
                    j++;
                }
                return ans;
            }
            
            if(nums[mid] > target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;   
    }
};