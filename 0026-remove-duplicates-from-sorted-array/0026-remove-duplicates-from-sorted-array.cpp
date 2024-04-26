class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        int k = nums.size();
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                k--;
                nums.erase(nums.begin()+i+1);
                i--;
            }
        }
        return k;
    }
};