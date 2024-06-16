class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        long long maxReach = 0;
        int patch = 0;
        int i=0;
        
    
        
        while(maxReach < n){
            //simple si baat h 
            //agr curr element maxReach se chota h ya equal h 
            //to wha tk ke saare elements definatly present honge
            if(i<nums.size() && nums[i] <= maxReach+1){
                maxReach += nums[i];
                i++;
            }
            else{
                //need to add patch
                maxReach += maxReach+1;
                patch++;
            }
        }
        
        return patch;
        
    }
};