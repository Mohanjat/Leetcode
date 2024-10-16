class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        int n = nums.size();
        
        if(sum % 2 != 0) return false;
        
        sum = sum/2;
        
        
       vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
        
       
        for(int i=0; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(i == 0) dp[i][j] = false;
                if(j == 0) dp[i][j] = true;
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
               if(nums[i-1] <= j){
               //inc and exc
               dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
               }
               else{
                 dp[i][j] = dp[i-1][j];
               }
           }
        }
        
        return dp[n][sum];
        
        
    }
};