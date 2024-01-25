class Solution {
public:
    bool canConstruct(string ransomNote, string magazine){
        
        int hash1[26] = {0};
        int hash2[26] = {0};
        
        for(int i=0; i<ransomNote.length(); i++){
            int val = ransomNote[i]-'a';
            hash1[val]++;
        }
        
        for(int i=0; i<magazine.length(); i++){
            int val = magazine[i]-'a';
            hash2[val]++;
        }
        
        for(int i=0; i<26; i++){
            if(hash1[i] != 0){
                if(hash2[i] == 0) return false;
                if(hash2[i] < hash1[i]) return false;
            }
        }
        
        return true;
    }
};