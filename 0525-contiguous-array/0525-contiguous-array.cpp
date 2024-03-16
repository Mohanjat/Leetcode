class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> countMap;
        countMap[0] = -1; // Initialize the count map with 0 at index -1
        int maxlen = 0, count = 0;
        
        for (int i = 0; i < n; i++) {
            count += (nums[i] == 1 ? 1 : -1); // Increment count for 1, decrement for 0
            if (countMap.find(count) != countMap.end()) { // If the count is already in the map, update maxlen
                maxlen = max(maxlen, i - countMap[count]);
            } else { // Otherwise, add the count to the map
                countMap[count] = i;
            }
        }
        
        return maxlen;
    }
};
