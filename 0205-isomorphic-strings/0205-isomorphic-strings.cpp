class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int hash1[256] = {0};//For storing mapping of t in s
        int hash2[256] = {0}; //For update visited of t string elements

        for(int i=0; i<s.length(); i++){
            if(hash1[s[i]] == 0 && hash2[t[i]] == 0){
                hash1[s[i]] = t[i];
                hash2[t[i]] = 1;
            }
        }

        //chech kya hum mapped string se t string bna skte h ya nhi 
        for(int i=0; i<s.length(); i++){
            if(char(hash1[s[i]]) != t[i]){
                 return false;
            }
        }
        return true;     
    }
};