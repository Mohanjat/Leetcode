class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        
        int n = s.length();
        
        while(n--){
            char ch = s[0];
            s.erase(0,1);
            s.push_back(ch);
            if(s == goal) return true;
        }
        
        return false;
    }
};