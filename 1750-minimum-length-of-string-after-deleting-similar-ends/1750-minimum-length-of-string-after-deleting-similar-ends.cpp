class Solution {
public:
    int minimumLength(string s) {
        
        //now lets try a simple solution
        
        int i=0;
        int j=s.length()-1;
        
        while(i<j && s[i] == s[j]){
            char ch = s[i];
            while(i<=j && s[i] == ch){
                i++;
            }
            while(j>=i && s[j] == ch){
                j--;
            }
        }
        
        return j-i+1;
        
        
        
//         int len = s.length();
//         int i=0; 
//         int j=len-1;
      
//         while(i<j && s.length()>2){
//             //first of all check suffix and prefix
            
//             if(s[i] == s[j]){
//                 //now apply the algo
//                 //step1-- cal the prefix
//                 while(i<j){
//                     if(s[i] != s[i+1]){
//                         i++;
//                         break;
//                     }else if(i+1 != j && s[i] == s[i+1]){
//                        i++;                
//                     }else{
//                         break;
//                     }
        
//                 }
                
//                 //step2-- cal the suffix
//                 while(i<j){
//                     if(s[j] != s[j-1]){
//                         j--;
//                         break;
//                     }else if(j-1 != i && s[j] == s[j-1]){
//                         j--;
//                     }
//                     else{
//                         break;
//                     }
//                 }
                
//                 //step5-- deleting prefix and suffix
        
//                 int l = s.length()-j-1;
//                 s.erase(s.begin(),s.begin()+i);
//                 s.erase(s.end()-l,s.end());
         
//             }
//             else{
//                 break;
//             }
//             i = 0;
//             j = s.length()-1;
            
//         }
        
//         // if(s.length() == 1) return 0;
//         if(s.length() == 2){
//             if(s[0] == s[1]) return 0;
//         }
        
//         return s.length();
    }
};