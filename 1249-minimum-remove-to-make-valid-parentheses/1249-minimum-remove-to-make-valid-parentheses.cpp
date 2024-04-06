class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> toRemove;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (st.empty()) {
                    toRemove.insert(i);
                } else {
                    st.pop();
                }
            }
        }
        
        while (!st.empty()) {
            toRemove.insert(st.top());
            st.pop();
        }
        
        string result = "";
        for (int i = 0; i < s.length(); ++i) {
            if (toRemove.count(i) == 0) {
                result += s[i];
            }
        }
        
        return result;
    }
};
