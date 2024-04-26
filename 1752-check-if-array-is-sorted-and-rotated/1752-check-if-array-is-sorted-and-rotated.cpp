class Solution {
public:
    bool check(vector<int>& nums) {
       
        int x = -1;
        for(int i=0; i<nums.size()-1; i++){
           if(nums[i] > nums[i+1]){
              x = i+1;
               break;
           }
        }
       
        if(x == -1) return 1;
        
        vector<int>check;
        
        for(int i=x; i<nums.size(); i++){
             check.push_back(nums[i]);
        }
        
        for(int i=0; i<x; i++){
            check.push_back(nums[i]);
        }
        
        for(int i=0; i<check.size()-1; i++){
            if(check[i]>check[i+1]) return 0;
        }
        
        return 1;
    }
};