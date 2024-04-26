class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0];
        int cnt = 1;
        
        for(int i=1; i<nums.size(); i++){
            if(cnt == 0){
                cnt = 1;
                ele = nums[i];
                continue;
            }
            if(nums[i] == ele){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        
//         int temp = 0;
        
//         for(int i=0; i<nums.size(); i++){
//             if(nums[i] == ele){
//                 temp++;
//             }
//         }
        return ele;
    }
};