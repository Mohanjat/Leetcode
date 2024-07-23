class Solution {
public:
    
    struct ComparePairs{
        bool operator()(const pair<int,int> &p1, const pair<int,int> &p2){
             if (p1.second == p2.second) {
            return p1.first < p2.first;  // sort by p1.first < p2.first if p1.second == p2.second
        }
            return p1.second > p2.second;  //compare based on second element;
        }
    };
    
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        
        for(auto i:nums){
            mp[i]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,ComparePairs> minHeap;
        
        for(auto it:mp){
            int val1 = it.first;
            int val2 = it.second;
            
            minHeap.push({val1,val2});
        }
        vector<int> ans;
        int prevFreq = -1;
        int prevVal = 0; 
        
        while(!minHeap.empty()){
            auto it = minHeap.top();
            minHeap.pop();
            
            int num = it.first;
            int freq = it.second;
            
            while(freq--) ans.push_back(num);
          
        }
        
        return ans;
    }
};