class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        
        int hashMap1[26] = {0};
        int hashMap2[26] = {0};
        
        for(int i=0; i<s.length(); i++){
            hashMap1[s[i]-'a']++;
            hashMap2[t[i]-'a']++;
        }
        
        for(int i=0; i<26; i++){
            if(hashMap1[i] != hashMap2[i]) return false;
        }
        return true;
    }
};