class Solution {
public:
//     int solve(string s,int &ans){
//        if(s.length() == 1) return ans;
//        ans++;
        
//        if(s[s.length()-1] == '0'){
//            return solve(s.substr(0,s.length()-1),ans);
//        }
        
//        int i = s.length()-1;
       
//         while(i>=0){
//             if(s[i] == '0'){
//                 s[i] = '1';
//                 break;
//             }
//             s[i] = '0';
//             i--;
//         }
        
//         if(i == -1){
//             //need to add one char in the string 
//             s.insert(0,1,'1');
//         }
        
//         return solve(s,ans);
       
//     }
    
    int numSteps(string s){
        
        //optimal approach with o(n)
        
        int op = 0;
        int carry = 0;
        
        for(int i=s.length()-1; i>=1; i--){
            if(((s[i]-'0') + carry) % 2 == 1){
                //odd waala case
                op += 2;
                carry = 1;
            }
            else{
               op++;   
            }
        }
        
        
        return op+carry;
        
        
        
//         int ans = 0;
        
//         return solve(s,ans);
        
        // return ans;
    }
};
