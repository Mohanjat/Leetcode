class Solution {
public:
    vector<int> singleNumber(vector<int>& nums){
        
        //Optimal approach using Bit Manipulation
        
          //step1 == xor all number  = xor
         //step2 == create a mask using xor & (-xor);
         //step3 == saperate all elements into two groups using mask & nums[i] 
        
        long long Xor = 0;
        
        for(auto i:nums){
            Xor ^= i;    
        }
        
        int mask = (Xor) & (-Xor); //xor ki right most set bit ka mask create ho jaayega
        
        int group_a = 0;
        int group_b = 0;
        
        //seperate all the elements into the two segments 
        for(int i=0; i<nums.size(); i++){
            if(nums[i] & mask){
                //means set bit
                group_a ^= nums[i];
            }
            else{
                group_b ^= nums[i];
            }
        }
        
        return {group_a,group_b};
        
        
        
        
//          unordered_map<int,int>mp;
        
//          for(int i=0; i<nums.size(); i++){
//              if(mp.find(nums[i]) != mp.end()){
//                  mp[nums[i]]--;
//                  if(mp[nums[i]] == 0) mp.erase(nums[i]);
//              }
//              else{
//                  mp[nums[i]]++;
//              }
//          }
        
//         vector<int> ans;
        
//         for(auto it:mp){
//             ans.push_back(it.first);
//         }
//         return ans;
    }
};