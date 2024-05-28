class Solution {
public:
    int equalSubstring(string s, string t, int maxCost){
        
        int i=0;
        int j=0;
        
        int maxLen = INT_MIN;
        int currCost = 0;
        
        while(j<s.length()){
            
            int temp = abs(s[j]-t[j]);
            
            currCost += temp;
            
            if(currCost > maxCost){
                int prevCost = abs(s[i]-t[i]);
                currCost -= prevCost;
                i++;
            }
            
            //normal flow
            maxLen = max(maxLen,j-i+1);
            
            j++;
            
        }
        
        return maxLen;
    }
};