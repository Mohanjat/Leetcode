class Solution {
public:
    int search(vector<int>& nums, int target) {
        //the intution is that 
        //pkka yaa to left half sorted hoga ya right half sorted hoga
        //agr target element sorted waale part m nhi h to ye sure h ki 
        //wo dusre paart m pda hoga
        
        int s = 0;
        int e = nums.size()-1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            
            if(nums[mid] == target) return mid;
            
            if(nums[s] <= nums[mid]){
                //means left waala part pkka sorted h
                //now check kr lo target element left m h ya right m
                if(nums[s]<=target && nums[mid]>=target){
                    //mtlb element left m hi h 
                    e = mid-1;
                }
                else{
                    //means element right m h
                    s = mid+1;
                }
            }
            else{
                //means right waala part pkka sorted h
                if(nums[mid]<=target && target<=nums[e]){
                    //means target pkka right m hi h
                    s = mid+1;
                }
                else{
                    //target left part m h 
                    e = mid-1;
                }
            }
        }
        return -1;
    }
};