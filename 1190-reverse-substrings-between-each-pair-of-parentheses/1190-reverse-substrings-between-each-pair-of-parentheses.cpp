class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<int> prevLen;
        string result;
        
        for(auto i:s){
            if(i == '('){
                prevLen.push(result.length());        
            }
            else if(i == ')'){
                int l = prevLen.top();
                prevLen.pop();
                reverse(result.begin()+l,result.end());
            }
            else{
                result.push_back(i);
            }
        }
        return result;
    }
};