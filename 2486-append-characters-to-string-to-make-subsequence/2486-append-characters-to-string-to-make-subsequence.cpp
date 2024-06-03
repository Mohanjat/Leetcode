class Solution {
public:
    int appendCharacters(string s, string t){
        
        int i=0;
        int j =0;
        
        while(i<s.length()){
            if(s[i] == t[j]){
                j++;
            }
            if(j == t.length()) return 0;
            i++;
        }
        
        return t.length()-j;
    }
};