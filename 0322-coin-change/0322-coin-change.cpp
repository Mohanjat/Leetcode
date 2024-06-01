class Solution {
public:
    
    int solve(vector<int> & coins,int amount,int coinCnt,vector<int> &dp){
        
        if(amount == 0){
            return 0;
        }
        
        if(amount < 0) return INT_MAX;
        
        if(dp[amount] != -1) return dp[amount];
        
        //at every situation we have all the possibalites of coins
        int mini = INT_MAX;
        
        for(int j=0; j<coins.size(); j++){
            int ans = solve(coins,amount-coins[j],coinCnt+1,dp);
            if(ans != INT_MAX) mini = min(mini,ans+1);
        }
        
        dp[amount] = mini;
        
        return dp[amount];
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount+1,-1);
            
        int ans = solve(coins,amount,0,dp);
        
        return ans == INT_MAX ? -1:ans;
    }
};