class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
//         for(int i=0; i<nums.size(); i++){
//            nums[i] = nums[i]*nums[i];
//         }
        
//         sort(nums.begin(),nums.end());
        
        //do this without using stl and tc bigof(n)
        
        int n = nums.size();
        int s = 0;
        int e = n-1;
        vector<int> ans(n);
        
        for(int i=n-1; i>=0; i--){
            if(abs(nums[s]) > abs(nums[e])){
                ans[i] = nums[s]*nums[s];
                s++;
            }
            else{
                ans[i] = nums[e]*nums[e];
                e--;
            }
        }
        
        return ans;
    }
};