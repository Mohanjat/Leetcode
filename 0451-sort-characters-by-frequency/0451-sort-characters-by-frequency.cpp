class Solution {
public:
    string frequencySort(string s){
        unordered_map<char,int>mp;
        
        for(auto i:s){
            mp[i]++;
        }
        
          
        // Define a custom comparator for the priority queue
        auto cmp = [](pair<int, char> left, pair<int, char> right) {
            return left.first < right.first;  // Max-heap based on frequency
        };
        
        // Create a max-heap (priority_queue) with the custom comparator
        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(cmp)> maxHeap(cmp);
        
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