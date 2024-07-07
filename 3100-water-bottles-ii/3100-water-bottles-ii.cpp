class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange){
          
        int ans = numBottles;
        
        while(numBottles >= numExchange){
            numBottles = numBottles - numExchange;
            numExchange++;
            ans++;
            numBottles++;
        }
        
        return ans;
        
    }
};