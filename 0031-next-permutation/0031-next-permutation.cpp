class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        next_permutation(nums.begin(), nums.end()); 
        
        // bool check = true;
        
//         for(int i=nums.size()-1; i>0; i--){
//             if(nums[i] > nums[i-1]){
//                 swap(nums[i],nums[i-1]);
//                 check = false;
//                 break;
//             }
//         }
        
//         if(check){
//             reverse(nums.begin(),nums.end());
//         }
    }
};