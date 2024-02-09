class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        
        for(int i=0;i<nums.size()-2; i++){
         //handle duplicate  
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            
            int j=i+1;
            int k=nums.size()-1;
            
            while(j<k){
                
                 int temp = nums[j]+nums[k];
                 int sum = nums[i]+temp;
                 
                 // cout<<"value of the sum is "<<sum<<endl;
                 if(sum == 0){
                     ans.push_back({nums[i],nums[j],nums[k]});
                     //handle duplicate
                     while(j<k && nums[j] == nums[j+1]){
                         j++;
                     }
                     while(j<k && nums[k] == nums[k-1]){
                         k--;
                     }
                     
                     j++;
                     k--;
                 }
                else if(sum < 0){
                    j++;
                }else{
                    k--;
                }
            }
            
        }
        
        return ans;
        
    }
};