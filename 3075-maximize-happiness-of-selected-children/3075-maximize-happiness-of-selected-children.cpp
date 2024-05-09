class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k){
        
        priority_queue<long long> maxHeap;
        
        for(auto i:happiness) maxHeap.push(i);
        
        vector<long long>temp;
        
        while(k--){
            temp.push_back(maxHeap.top());
            maxHeap.pop();
        }
        
        long long sum = 0;
        
        for(int i=0; i<temp.size(); i++){
            if(temp[i]-i < 0) continue;
            sum += temp[i]-i;
        }
        
        return sum;
        
    }
};