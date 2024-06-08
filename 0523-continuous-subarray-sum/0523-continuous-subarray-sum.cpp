class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    
        unordered_map<int,int> mp;
        
        mp[0] = -1;
        
        int sum = 0;
    
        for(int i=0; i<nums.size(); i++){
            
            sum += nums[i];
            int rem = sum % k;
    
            if(mp.find(rem) != mp.end()){
                int index = mp[rem];
                if(i-index > 1){
                    return true;
                }
            }
            else{
                 mp[rem] = i;
            }
            
        }
        
        return false;
        
    }
};