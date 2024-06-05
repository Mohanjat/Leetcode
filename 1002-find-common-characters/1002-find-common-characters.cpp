class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        if(words.size() == 1) return words;
        
        string str = words[0];
        
        for(int i=1; i<words.size(); i++){
            string check = words[i];
            
            //now remove those chars from str, those not present in the check
            for(int j=0; j<str.length(); j++){
                if(check.find(str[j]) == string::npos){
                    //means curr char is not present in the check
                    //than need to erase currchar from the str
                    str.erase(j,1);
                    j--;
                }
                else{
                    //if the char find in the check than delete it from there
                    int pos = check.find(str[j]);
                    check.erase(pos,1);
                }
            }
        }
        
        vector<string> ans;
        
        for(int i=0; i<str.length(); i++){
            string newStr(1,str[i]);
            ans.push_back(newStr);
        }
        
        return ans;
        
    }
};