class Solution {
public:
    void sortColors(vector<int>& nums){
        int i=0;
        int k=0;
        int j=nums.size()-1;
        
        while(k<=j){
            if(nums[k] == 0){
                //place 0's to its right possition
                swap(nums[k],nums[i]);
                i++;
                k++;
            }
            else if(nums[k] == 1){
                //place 1's to its right possition
                k++;
            }
            else{
                //place 2's to its right possition
                swap(nums[k],nums[j]);
                j--;
            }
        }
          
    }
};