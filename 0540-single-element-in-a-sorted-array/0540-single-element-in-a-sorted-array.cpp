class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        //Approach#2 got intution by index 
        //first occurance of any element should be even if the single element 
        //lies in the opposite half of the array
        
        int s = 0;
        int e = nums.size()-1;
        if(nums.size() == 1) return nums[0];
        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(mid+1 == nums.size() && nums[mid-1] != nums[mid]) return nums[mid];
            if(mid-1 < 0 && nums[mid+1] != nums[mid]) return nums[mid];
            
            //agr mid hi single element ho to
            if((mid+1<nums.size() && nums[mid+1] != nums[mid]) && (mid-1>=0 &&                     nums[mid-1] != nums[mid])) return nums[mid];
            
            int occ1;
            int occ2;
            if(mid+1<nums.size() && nums[mid+1] == nums[mid]){
                occ1 = mid;
                occ2 = mid+1;
            }
            
            if(mid-1>=0 && nums[mid-1] == nums[mid]){
                occ1 = mid-1;
                occ2 = mid;
            }
        
            if(occ1%2 == 0){
                //means first occurance is even
                //then single deffinetly dont lies in the left part
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        
        return -1;
        
       //  int ans = 0;
       // for(int i=0; i<nums.size(); i++){
       //     ans = ans^nums[i];
       // }
       //  return ans;
    }
};