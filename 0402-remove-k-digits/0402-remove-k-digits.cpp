class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char>st;
        
        for(auto digit:num){
            //agr stack ke uper curr se bdi digit h to hta do
            while(!st.empty() && k>0 && st.top() > digit){
                st.pop();
                k--;
            }
            //push curr digit
            st.push(digit);
        }
        
        //delete remaining k elements
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        
        //construct string from all char present in the stack
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        //reverse the string 
        reverse(ans.begin(),ans.end());
        
        //remove leading zeros
        
        size_t pos = ans.find_first_not_of('0');
        
        ans = (pos == std::string::npos) ? "0" : ans.substr(pos);
        
        return ans;
    }
};