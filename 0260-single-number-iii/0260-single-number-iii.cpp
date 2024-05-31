class Solution {
public:
    vector<int> singleNumber(vector<int>& nums){
        
         unordered_map<int,int>mp;
        
         for(int i=0; i<nums.size(); i++){
             if(mp.find(nums[i]) != mp.end()){
                 mp[nums[i]]--;
                 if(mp[nums[i]] == 0) mp.erase(nums[i]);
             }
             else{
                 mp[nums[i]]++;
             }
         }
        
        vector<int> ans;
        
        for(auto it:mp){
            ans.push_back(it.first);
        }
        return ans;
    }
};