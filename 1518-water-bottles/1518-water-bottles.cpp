class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int ans = numBottles;
        
        while(numBottles >= numExchange){
            
            int divisor = numBottles / numExchange;
            int remainder = numBottles % numExchange;
            
            ans += divisor;
            
            numBottles = divisor + remainder;
        }
        
        return ans;
    }
};