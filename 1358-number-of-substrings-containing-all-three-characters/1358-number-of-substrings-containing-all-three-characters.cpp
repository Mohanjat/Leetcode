class Solution {
public:
    int numberOfSubstrings(string s){
        
        int hashMap[3] = {-1,-1,-1};
        int ans = 0;
        
        for(int i=0; i<s.length(); i++){
            
            hashMap[s[i]-'a'] = i;
            
            if(hashMap[0] != -1 && hashMap[1] != -1 && hashMap[2] != -1){
                int minIndex = min(hashMap[0],min(hashMap[1],hashMap[2]));
                ans += minIndex+1;
            }
        }
        return ans;
    }
};