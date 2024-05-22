class Solution {
public:
    
    bool checkPalindrome(string &s,int i,int j){
        
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    void solve(string &s, vector<string> &strs,int i, vector<vector<string>>&ans){
        
        if(i==s.length()){
            ans.push_back(strs);;
            return;
        }
        
       //explore all the possibilities
        for(int j=i+1; j<=s.length(); j++){
            
            //check if the curr sub stirng is palindrome or nor
            if(checkPalindrome(s,i,j-1)){
                //add the curr string into the answer and explore further
                strs.push_back(s.substr(i,j-i));
                //check further
                solve(s,strs,j,ans);
                //backtrack
                strs.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s){
        
        vector<vector<string>> ans;
        vector<string> strs;
        solve(s,strs,0,ans);
        
        return ans;
    }
};