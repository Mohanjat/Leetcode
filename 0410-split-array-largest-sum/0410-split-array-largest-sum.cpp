class Solution {
public:
    
    bool isPossible(int mid, vector<int>&nums,int k){
        
        for(int i=0; i<nums.size(); i++){
            int sum = 0;
            while(i<nums.size() && sum<=mid){
                sum += nums[i];
                if(sum>mid){
                    k--;
                    i--;
                    break;
                }
                i++;
            }
            //means the mid is not possible
            if(k<0 || (k == 0 && i<nums.size())) return false;
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int k){
        
        if(k > nums.size()) return -1;
        
        int maxi = INT_MIN;
        int sum = 0;
        
        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi,nums[i]);
            sum += nums[i];
        }
        
        int s = maxi;
        int e = sum;
        int ans = INT_MAX;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            
            //check that if mid is possible or not 
            if(isPossible(mid,nums,k)){
                //if mid is possible that search for better answer
                ans = min(ans,mid);
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};