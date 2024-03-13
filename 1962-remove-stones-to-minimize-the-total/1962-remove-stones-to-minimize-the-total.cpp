class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> pq;
        
        for(int i=0; i<piles.size(); i++){
            pq.push(piles[i]);
        }
        
        while(k!=0){
            int top = pq.top();
            int temp = top;
            if(top&1){
                temp = (top/2)+1;
            }
            else{
                temp = top/2;
            }
            
            pq.pop();
            pq.push(temp);
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