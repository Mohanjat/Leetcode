class Solution {
public:
    
    void merge(vector<int>&nums,int k,int s, int e, int mid){
        
        int leftSize = mid-s+1;
        int rightSize = e-mid;
        int* leftArr = new int[leftSize];
        int* rightArr = new int[rightSize];
        
        int mainIndex = s;
        
        for(int i=0; i<leftSize; i++){
            leftArr[i] = nums[mainIndex++];
        }
        
        mainIndex = mid+1;
        
        for(int i=0; i<rightSize; i++){
            rightArr[i] = nums[mainIndex++];
        }
        
        int leftIdx = 0;
        int rightIdx = 0;
        mainIndex = s;
        
        while(leftIdx < leftSize && rightIdx < rightSize){
            if(leftArr[leftIdx] < rightArr[rightIdx]){
                nums[mainIndex++] = leftArr[leftIdx++];
            }
            else{
                nums[mainIndex++] = rightArr[rightIdx++];
            }
        }
        
        while(leftIdx < leftSize){
             nums[mainIndex++] = leftArr[leftIdx++];
        }
        
        while(rightIdx < rightSize){
            nums[mainIndex++] = rightArr[rightIdx++];   
        }
        
        
    }
    
    void solve(vector<int>&nums,int k,int s, int e){
        if(s>=e){
            return;
        }
        
        int mid = s + (e-s)/2;
        
        //left se ans nikaalo
        solve(nums,k,s,mid);
        
        //right se ans nikaalo
        solve(nums,k,mid+1,e);
        
        merge(nums,k,s,e,mid);
        
    }
    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        //solving using merge sort

        // solve(nums,k,0,nums.size()-1);
        
        int i=0;
        int j=0;
        int ans = 0;
        
        while(j<nums.size()){
            int mul = 1;
            while(j<nums.size() && mul < k){
                mul *= nums[j];
                if(mul >= k){
                    break;
                }
                ans++;
                j++;
            }
            i++;
            j = i;
        }
    
        return ans;
    }
};