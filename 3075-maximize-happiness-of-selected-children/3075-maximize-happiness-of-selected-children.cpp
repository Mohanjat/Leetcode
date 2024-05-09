class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k){
        
        priority_queue<long long> maxHeap;
        
        for(auto i:happiness) maxHeap.push(i);
        
        long long sum = 0;
        int cnt = 0;
        
        while(k--){
            if(maxHeap.top()-cnt < 0) continue;
            sum += maxHeap.top()-cnt;
            cnt++;
            maxHeap.pop();
        }
        
        return sum;
        
    }
};