class Solution {
public:
    string makeGood(string s){
        
        int i = 0;
        
        while(!s.empty() && i<s.length()-1){
    
            if(isupper(s[i]) && islower(s[i+1])){
                if(tolower(s[i]) == s[i+1]){
                    s.erase(i,2);
                    i = (i > 0) ? i - 1 : 0; // Decrement i if it's greater than 0
                }
                else{
                    i++;
                }
            }
            else if(isupper(s[i+1]) && islower(s[i])){
                if(tolower(s[i+1]) == s[i]){
                    s.erase(i,2);
                    i = (i > 0) ? i - 1 : 0; // Decrement i if it's greater than 0
                }
                else{
                    i++;
                }
            }
            else{
                i++;
            }
            
        }
        return s;
    }
};
