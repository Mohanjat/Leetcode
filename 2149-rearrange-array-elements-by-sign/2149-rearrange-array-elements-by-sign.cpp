class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int>a;
        vector<int>b;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0){
                b.push_back(nums[i]);
            }
            else{
                a.push_back(nums[i]);
            }
        }
        
        int i=0; 
        int j=0;
        int index = 0;
        
        while(i<a.size()){
            nums[index] = a[i];
            index++;
            nums[index] = b[j];
            index++;
            i++;
            j++;
        }
        return nums;
    }
};