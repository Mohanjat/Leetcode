class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        unordered_map<int,int> map;
        
        for(auto i:nums){
            map[i]++;
        }
        
        int n = nums.size();
        
        for(int i=1; i<=n; i++){
            if(map.find(i) == map.end()){
                return i;
            }
        }
        return n+1;
    }
};