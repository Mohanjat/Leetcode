class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<pair<char,int>>st;
        
        for(int i=0; i<s.length(); i++){
            //if stack is empty push the element 
            char ch = s[i];
            
            if(ch == '('){
                //push kro
                st.push({'(',i});
            }
            else if(ch == ')' && st.size() == 1){
                //now its deffinately a outermost bracket
                auto [ch,index] = st.top();
                st.pop();
                //now we have to delete i and index from string s
                s.erase(i,1);
                s.erase(index,1);
                //to remain on the same index 
                i = i-2;
            }
            else{
                st.pop();
            }
        }
        
        return s;
    }
};