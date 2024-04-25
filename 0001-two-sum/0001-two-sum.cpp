class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(target-nums[i]-nums[j] == 0){
                    return {i,j};
                }
            }
        }
        return {0,0};
    }
};