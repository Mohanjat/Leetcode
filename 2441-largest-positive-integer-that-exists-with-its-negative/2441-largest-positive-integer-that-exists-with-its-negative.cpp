class Solution {
public:
    int findMaxK(vector<int>& nums){
        
        unordered_map<int,int> mp;
        
        for(auto i:nums){
            if(i<0){
                mp[abs(i)]++;
            }    
        }
        
        int maxi = -1;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0) continue;
            
            if(mp.find(nums[i]) != mp.end()){
                maxi = max(maxi,nums[i]);
            }
        }
        return maxi;
    }
};