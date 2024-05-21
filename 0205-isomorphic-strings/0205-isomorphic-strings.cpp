class Solution {
public:
    bool isIsomorphic(string s, string t) {
       
       if(s.length() != t.length()) return false;
        
       unordered_map<char,char>mp;
        
       int hashMap[256] = {0};
        
       int i=0;
        
        while(i<s.length()){
            
            if(mp.find(s[i]) != mp.end()){
                //means the char is found
                //now check, is curr char is matched correctly of not
                char mappedChar = mp[s[i]];
                if(mappedChar != t[i]) return false;
                
            }
            else{
                //t[i] ko tbhi map krenge jb wo phle se map na ho
                if(hashMap[t[i]] == 1) return false;
                //normal flow
                mp[s[i]] = t[i];
                //and mark the curr char visited
                hashMap[t[i]] = 1;
            }
            
            i++;
        }
        
       return true;
        
    } 
};