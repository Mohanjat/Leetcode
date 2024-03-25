class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
          vector<int> ans;
        
          for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                ans.push_back(index + 1);
            } else {
                nums[index] *= -1;
            }
        }
        
        return ans;
        
//         unordered_map<int,int> map;
        
//         for(auto i:nums){
//             map[i]++;
//         }
        
//         vector<int> ans;
        
//         for(auto i:map){
//             if(i.second>1){
//                 ans.push_back(i.first);
//             }
//         }
//         return ans;
    }
};