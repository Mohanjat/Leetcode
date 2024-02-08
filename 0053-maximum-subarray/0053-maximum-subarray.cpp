class Solution {
public:

    int maxSumArr(vector<int> &nums, int s, int e){

        if(s >= e) return nums[s];

        int mid = s + ((e-s) >> 1);

        //left ka ans nikal lo
        int leftMax = maxSumArr(nums, s, mid);
        //right ka ans nikal lo
        int rightMax = maxSumArr(nums, mid+1, e);

        int leftBorderSum = 0, rightBorderSum = 0;
        int maxleftBorderSum = INT_MIN, maxrightBorderSum = INT_MIN;

        //left part ko traverse kr lo
        for(int i=mid; i>=s; i--){
            leftBorderSum += nums[i];
            if(leftBorderSum > maxleftBorderSum) maxleftBorderSum = leftBorderSum;
        }

        //right part ko traverse kr lo
        for(int i=mid+1; i<=e; i++){
            rightBorderSum += nums[i];
            if(rightBorderSum > maxrightBorderSum) maxrightBorderSum = rightBorderSum;
        }

        int crossBorderSum = maxrightBorderSum + maxleftBorderSum;

        return max(leftMax,max(rightMax,crossBorderSum));
        
    }

    int maxSubArray(vector<int>& nums) {

        //By Merge Sort

        return maxSumArr(nums,0,nums.size()-1);








        // //By Kadane's Algo

        // int sum = 0;
        // int maxi = INT_MIN;

        // for(int i=0; i<nums.size(); i++){
        //     //step1:- current sum 
        //     sum += nums[i];

        //     //step2:- max sum ko update kr lo
        //     maxi = max(maxi,sum);

        //     //step3:- agr sum -ve ho jaaye to sum ko zero kr do
        //     if(sum < 0) sum = 0;
        // }
        
        // return maxi;
    }
};