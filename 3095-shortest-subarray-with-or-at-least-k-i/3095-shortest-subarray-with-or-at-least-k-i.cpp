class Solution {
public:
    
    int ans = INT_MAX;
    
    void solve(vector<int> &nums,int k,int i){
        if(i>=nums.size()) return;
        
        int sum = 0;
        
        for(int j=i; j<nums.size(); j++){
            sum |= nums[j];
            if(sum >= k){
                ans = min(ans,j-i+1);
            }
        }
        
        solve(nums,k,i+1);
        
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        
        solve(nums,k,0);
        
        return ans == INT_MAX ? -1 : ans;
    }
};