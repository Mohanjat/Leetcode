class Solution {
public:
    int longestOnes(vector<int>& nums, int k){
        
        int i = 0;
        int j = 0;
        int maxLen = INT_MIN;
        
        while(j<nums.size()){
            
            //kind of base we can that
            if(nums[j] == 0 && k == 0){
                while(true){
                    if(nums[i] == 0){
                        k++;
                        i++;
                        break;
                    }
                    i++;
                }
            }
            
            //normal flow
            if(nums[j] == 1){
                //update the maxlen
                maxLen = max(maxLen,j-i+1);
                j++;
            }
            else if(nums[j] == 0 && k>0){
                maxLen = max(maxLen,j-i+1);
                j++;
                k--;
            }
        }
        return maxLen;
    }
};