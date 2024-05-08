class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold){
        
        long long s = 0;
        long long e = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(s > nums[i]) s = nums[i];
            if(e < nums[i]) e = nums[i];
        }
        
        if(threshold == nums.size()) return e;
        
        long long ans = INT_MAX;
        
        while(s<=e){
            double mid = s+(e-s)/2;
            double divisor = 0;
            for(int i=0; i<nums.size(); i++){
                divisor += ceil(nums[i]/mid);
            }
            
            if(divisor <= threshold){
                //means it's a valid divisor and now check for smallest
                 //store the answer if it is minimum
                if(ans>mid) ans = mid;
                e = mid-1;
            }
            else{
                //divisor is not possible check for further
                s = mid+1;
            }
        }
        
        return ans;
    }
};