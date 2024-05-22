class Solution {
public:
    
    bool checkPalin(string &s, int i,int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            
            i++;
            j--;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        if(s.length() == 1) return s;
        int i=0;
        int j=1;
        string ans = "";
        
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                if(checkPalin(s,i,j)){
                    string temp = s.substr(i,j-i+1);
                    if(temp.length() > ans.length()) ans = temp;
                }
            }
        }
        
        return ans;
    }
};