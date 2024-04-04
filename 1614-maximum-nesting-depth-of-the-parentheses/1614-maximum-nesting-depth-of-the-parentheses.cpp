class Solution {
public:
    int maxDepth(string s) {
        
        stack<pair<char,int>> st;
        
        int i=0;
        int cnt = 0;
        int depth = INT_MIN;
        
        while(i<s.length()){
            char ch = s[i];
            if(st.empty() && ch == ')') continue;
            
            if(ch == '('){
                cnt++;
                st.push({'(',cnt});
            }
            else if(ch == ')'){
                // while(st.top() != '('){
                //     st.pop();
                // }
                pair<char,int> temp = st.top();
                st.pop();
                depth = max(depth,temp.second);
                cnt--;
            }
            i++;
        }
        
        return depth == INT_MIN ? 0:depth;
        
    }
};