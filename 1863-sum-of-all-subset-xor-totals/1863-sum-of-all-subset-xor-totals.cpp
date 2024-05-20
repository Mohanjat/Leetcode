class Solution {
public:
    
    void solve(vector<int>&nums,int &ans,int x,int i){
        if(i >= nums.size()){
            ans += x;
            return;
        }
        
        //include the curr element
        solve(nums,ans,x^nums[i],i+1);
        //exclude the curr element
        solve(nums,ans,x,i+1);
        
    } 
    
    int subsetXORSum(vector<int>& nums) {
        
        //using include and exclude
        int ans = 0;
        solve(nums,ans,0,0);
        
        return ans;
    }
};