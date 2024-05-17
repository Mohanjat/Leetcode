class Solution {
public:
    string frequencySort(string s){
        unordered_map<char,int>mp;
        
        for(auto i:s){
            mp[i]++;
        }
        
        priority_queue<pair<int,char>> maxHeap;
        
        for(auto it:mp){
            maxHeap.push({it.second,it.first});
        }
        
        string str = "";
        
        while(!maxHeap.empty()){
            auto [num,ch] = maxHeap.top();
            maxHeap.pop();
            str.append(num,ch);
        }
        return str;
    }
};