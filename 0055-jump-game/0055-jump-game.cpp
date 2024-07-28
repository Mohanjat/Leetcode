class Solution {
public:
    bool canJump(vector<int>& nums){
        
        int maxLen = 0;
        
        for(int i=0; i<nums.size(); i++){
             if(i > maxLen) return false;
            
            maxLen = max(maxLen, i+nums[i]);
        }
        
        return 1;
        
//         for(int i=0; i<nums.size(); i++){
//              int curr = nums[i];
            
//             if(i != nums.size()-1 && nums[i] == 0) return 0;
//             curr--;
//             if(curr == 0) continue;
//             i++;

            
//             while(i<nums.size() && curr != 0){
//                 if(nums[i] > curr){
//                     i--;
//                     break;
//                 }
//                 curr--;
//                 if(curr == 0) break;
//                  i++;
//             }
//         }
        
//         return 1;
       
    }
};