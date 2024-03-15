class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // vector<int> ans(nums.size(),0);

        // int p = 1;
        // int cnt = 0;

        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i] != 0){
        //         p *= nums[i];
        //     }
        //     else{
        //         cnt++;
        //     }
        // }
        // // cout<<"this is the value of p "<<p<<endl;

        // if(cnt > 1) return ans;

        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i] == 0){
        //         ans[i] = p;

        //     }
        //     else if(cnt == 1){
        //         continue;
        //     }
        //     else{
        //         int product = p/nums[i];
        //         ans[i] = product;

        //     }
        // }

        // return ans;






        // **************************************

        //better Approach

        //left elements ka product or
        //right elements ka product  store kr lo
        //now we have product of right and left elements
        //simply add it simply 
        
        int n = nums.size();
        vector<int> ans(n);

        ans[0] = 1;

        //storing left Array ka product
        for(int i=1; i<n; i++){
            ans[i] = ans[i-1]*nums[i-1];
        }

        //storing right array ka product into a variable and update it
        int right = 1;

        for(int i = n-1; i>=0; i--){
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;
    }
};