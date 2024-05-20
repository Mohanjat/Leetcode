class Solution {
public:
    int characterReplacement(string s, int k) {
        
        //using sliding window and using hash map of 26 size
        //the intution is that -- number of changes we have to do is ==
        // currlen - maxFreq 
        
        int l = 0;
        int r = 0;
        int maxFreq = 0;
        int maxLen = 0;
        int hashMap[26] = {0};
        
        while(r < s.length()){
            //increase the freq of the curr char
            hashMap[s[r]-'A']++;
            
            //update the maxFreq
            maxFreq = max(maxFreq,hashMap[s[r]-'A']);
            
            //check for valid substring
            int currLen = r-l+1;
            if(currLen-maxFreq > k){
                //means there the more elements we need to change
                //shrink the window size
                hashMap[s[l]-'A']--;
                
                maxFreq = 0;
                //now update the maxFreq
                for(int i=0; i<26; i++){
                    maxFreq = max(maxFreq,hashMap[i]);
                }
                
                l++;
            }
            else{
                //means it's a valid window
                maxLen = max(maxLen,currLen);
            }
            r++;
        }
        return maxLen;
    }
};