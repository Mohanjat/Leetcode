class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> freq;
        
        for (int num : nums) {
            freq[sum]++;
            sum += num;
            ans += freq[sum - goal];
        }
        
        return ans;
        
    }
};