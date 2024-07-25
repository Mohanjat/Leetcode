class Solution {
public:
    
    void merge(vector<int> &nums,int s, int e,int mid){
        
        int len1 = mid-s+1;
        int len2 = e-mid;
        
        int * arr1 = new int[len1];
        int * arr2 = new int[len2];
        
        int index = s;
        
        for(int i=0; i<len1; i++){
            arr1[i] = nums[index++]; 
        }
        
        index = mid+1;
        
        for(int i=0; i<len2; i++){
            arr2[i] = nums[index++];
        }
        
        int i = 0;
        int j = 0;
        int mainIdx = s;
        
        while(i<len1 && j<len2){
            if(arr1[i] < arr2[j]){
                nums[mainIdx++] = arr1[i++];
            }
            else{
                nums[mainIdx++] = arr2[j++];
            }
        }
        
        while(i<len1){
            nums[mainIdx++] = arr1[i++];
        }
        
        while(j<len2){
            nums[mainIdx++] = arr2[j++];
        }
        
        
    }
    
    void solve(vector<int> &nums, int s, int e){
        
        if(s >= e) return;
        
        int mid = s + (e-s)/2;
        
        solve(nums,s,mid);
        solve(nums,mid+1,e);
        
        merge(nums,s,e,mid);
        
         
    }
    
    vector<int> sortArray(vector<int>& nums) {
        
        int s = 0;
        int e = nums.size()-1;
        
        solve(nums,s,e);
        
        return nums;
    }
};