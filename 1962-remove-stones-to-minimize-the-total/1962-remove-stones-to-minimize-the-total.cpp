class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> pq;
        
        for(int i=0; i<piles.size(); i++){
            pq.push(piles[i]);
        }
        
        while(k!=0){
            int top = pq.top();
            pq.pop();
            top = top-floor(top/2);    
            pq.push(top);
            k--;
        }
        
        int ans = 0;
        
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};