class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        //intutuion is simple 
        //agr 34%4 == 2 than agr isme hum 4 ka koi bhi multiple add krenge to 
        //bhi remain 2 hi aayega like -- 38%4 == 2 and so on
    
    
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