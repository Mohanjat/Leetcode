class Solution {
public:
    int minimumDeletions(string s) {
        
        stack<char> st;
        
        int op = 0;
        
        for(int i=0; i<s.length(); i++){
           if(!st.empty() && st.top() == 'b' && s[i] == 'a'){
               op++;
               st.pop();
           }
            else{
                st.push(s[i]);
            }
           
        }
        
        return op;
        
    }
};