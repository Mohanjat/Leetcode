class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int l = s.length();
        if(l==1) return s;
        //first of all make the number odd
        for(int i=0; i<l; i++){
            if(s[i] == '1'){
                swap(s[i],s[l-1]);
            }
        }
        
        //now make the string maximum
        int i=0;
        int j=l-2;
        
        while(i<j){
            while(i<j){
                if(s[i] == '0') break;
                i++;
            }
            while(i<j){
                if(s[j] == '1') break;
                j--;
            }
            if(s[i] == '0' && s[j] == '1'){
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        
        return s;
    }
};