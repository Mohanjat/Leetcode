class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> map;
        
        for(auto i:nums){
            map[i]++;
        }
        
        int maxOcc = 0;
        
        for(auto i: map){
            int freq = i.second;
            maxOcc = max(maxOcc,freq);
        }
        
        int ans = 0;
        

        for(auto i:map){
            if(i.second == maxOcc){
                ans += maxOcc;
            }
        }
        
        return ans;
        
    }
};