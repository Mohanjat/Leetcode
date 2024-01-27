class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int i=0;
        int j=0;
        string ans= "";
        
        while(i<word1.length() && j<word2.length()){
            if(i<=j){
                ans.push_back(word1[i]);
                i++;
            }
            else{
                ans.push_back(word2[j]);
                j++;
            }
        }
        
        if(i<word1.length()){
            string str = word1.substr(i);
            ans += str;
        }
        
        if(j<word2.length()){
            string str = word2.substr(j);
            ans += str;
        }
        
        return ans;
    }
};