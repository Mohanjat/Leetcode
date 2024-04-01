class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length()-1;
        
        for(; i>=0; i--){
            if(s[i] != ' ') break;
        }
        
        int ans = 0;
        
        while(i>=0){
            if(s[i] == ' '){
                break;
            }
            i--;
            ans++;
        }
        return ans;
    }
};