class Solution {
public:
    int longestPalindrome(string s){
        
        int hashMap[256] = {0};
        
        for(int i=0; i<s.length(); i++){
            hashMap[s[i]]++;
        }
        
        int isOdd = false;
        int len = 0;
        
        for(int i=0; i<256; i++){
            int val = hashMap[i];
            if(val == 0)continue;
            if(val == 1){
                isOdd = true;
                continue;
            }
            
            if(val%2 == 0){
                len += val;
            }
            else{
                len += val-1;
                isOdd = true;
            }
            
        }
        
        cout<<len<<endl;
        
        return isOdd ? len+1: len;
    }
};