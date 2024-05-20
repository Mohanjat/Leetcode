class Solution {
public:
    int myAtoi(string s) {
        
        int i=0;
        
        //check for whitespaces
        while(i<s.length() && s[i] == ' ') i++;
        
        //check for sign
        bool checkMinus = false;
        if(i<s.length() && s[i] == '-'){
            i++;
            checkMinus = true;
        }
        else if(i<s.length() && s[i] == '+'){
            i++;
        }
        
        int j = i;
        
        while(j<s.length() && isdigit(s[j])){
            j++;
        }
        
        //means there is no valid integer
        if(j == i) return 0;
        
          // Convert substring to integer
        long long ans = 0;
        
        try {
            ans = stoll(s.substr(i, j - i));
        } catch (out_of_range & e) {
            // Handle potential overflows
            return checkMinus ? INT_MIN : INT_MAX;
        }
        
        // Apply sign
        if (checkMinus) {
            ans = -ans;
        }
        
        // Clamp to INT_MIN and INT_MAX
        if (ans < INT_MIN) return INT_MIN;
        if (ans > INT_MAX) return INT_MAX;
        
        return ans;
    }
};