class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //using hash-table
        unordered_map<int,int> hashMap;
        
        for(int i=0; i<nums.size(); i++){
            hashMap[nums[i]] = i;
        }
        
        for(int i=0; i<nums.size(); i++){
            int temp = target-nums[i];
            if(hashMap.find(temp) != hashMap.end() &&hashMap[temp] != i){
                return {i,hashMap[temp]};
            }
        }
        
        return {};
        //brute force
        
        // for(int i=0; i<nums.size(); i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         if(target-nums[i]-nums[j] == 0){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {0,0};
    }
};