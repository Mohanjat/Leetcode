class Solution {
public:
    
    int findPivot(vector<int>&nums){
        int s = 0;
        int e = nums.size()-1;
        
        while(s<=e){
             int mid = s+(e-s)/2;
            if(mid+1<nums.size() && nums[mid+1] < nums[mid]){
                return mid;
            }
            if(mid-1>=0 && nums[mid-1]>nums[mid]){
                return mid;
            }
            
            if(nums[s] <= nums[mid]){
                //means left part is sorted and pivot deffinetaly lies in the right part
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            
        }
        return -1;
    }
    
    int findMin(vector<int>& nums){
        
        //answer should lies in the right part of the pivot index;
        
        int pivotIndex = findPivot(nums);
        
        cout<<"value of pivotIndex "<<pivotIndex<<endl;
        
        if(pivotIndex == -1) return nums[0];
        
        //ye to pivot index hi smallest h ya phir pivotIndex+1 smallest h
        if(pivotIndex+1<nums.size() && nums[pivotIndex] < nums[pivotIndex+1]) 
            return nums[pivotIndex];
        else 
            return nums[pivotIndex+1];
        
        
    }
};