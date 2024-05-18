class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int j=0;    
        
        while(j<s.length() && s[j] == ' '){
            j++;
        }
        
        for(int i=j; i<s.length(); i++){
            
            if(s[i] == ' ') continue;
            
            string word = "";
            
            while(i<s.length() && s[i] != ' '){
                word.push_back(s[i]);
                i++;
            }
            
            if(i != s.length()){
                st.push(word);
                char ch = ' ';
                string str(1,ch);
                st.push(str);
            }
            else{
                st.push(word);
                break;
            }
        }
        
        string ans = "";
        
        while(!st.empty()){
            if(st.top() == " "){
                st.pop();
            }
            break;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
        
    }
};