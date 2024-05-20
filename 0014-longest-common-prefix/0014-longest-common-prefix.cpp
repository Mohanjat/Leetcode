class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() == 1) return strs[0];
        
        string newStr = strs[0];
        
        for(int i=0; i<newStr.length(); i++){
            for(int j=1; j<strs.size(); j++){
                string temp = strs[j];
                if(temp[i] != newStr[i]){
                    return newStr.substr(0,i);
                }
                
            }
            if(i == newStr.length()-1) return newStr;
        }
        return "";
    }
};