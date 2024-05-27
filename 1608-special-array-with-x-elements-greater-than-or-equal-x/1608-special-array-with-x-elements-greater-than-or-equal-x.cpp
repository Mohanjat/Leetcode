class Solution {
public:
    
    int check(int mid, vector<int>&nums){
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=mid)cnt++;
        }
        return cnt;
    }
    
    int specialArray(vector<int>& nums) {
        int s = 0;
        int e = -1;
        
        for(int i=0; i<nums.size(); i++){
            e = max(e,nums[i]);
        }
        
        while(s<=e){
            int mid = s + (e-s)/2;
            
            int cnt = check(mid,nums);
            
            if(cnt == mid){
                return mid;
            }
            
            if(cnt>mid){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return -1;
    }
};