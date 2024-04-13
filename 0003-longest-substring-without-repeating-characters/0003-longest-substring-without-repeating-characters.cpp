class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.empty()) return 0;
        //keep tracking of the characters, use hash table
        unordered_map<char,int> map;
        
        int i=0;
        int j=0;
        int maxLen = INT_MIN;
        
        while(j<s.length()){
            char currCh = s[j];
            if(map.find(currCh) != map.end()){
                //means char is already present
                //need to change ith index
                map.erase(s[i]);
                i++;
            }
            else{
                map[currCh]++;
                maxLen = max(maxLen,j-i+1);
                j++;
            }
        }
        
        return maxLen;
    }
};