class Solution {
public:
    
    typedef long long ll;
    
    long long wonderfulSubstrings(string word){
        
        unordered_map<ll,ll> mp;
        
        mp[0] = 1; //000 ki entry map m add kr do
        
        ll result = 0;
        int cumulative_xor = 0;
        
        for(auto ch:word){
            int shift = ch-'a'; //binary reprsentation of char
            //curr char tk ka total xor nikaal lo
            cumulative_xor ^= (1<<shift);
            
            //if all the chars present even number of times than
            //cumulative xor should presents in the map 
            result += mp[cumulative_xor];
                
            //now check if the 1 char present odd number of times
            for(char c='a'; c<='j'; c++){
                shift = c-'a';
                
                ll check_xor = (cumulative_xor ^ (1<<shift));
                
                //if the check xor present in the map than
                //we can say only one odd char is present
                result += mp[check_xor];
            }
            
            //increase the count of  the cumulative xor in map
            mp[cumulative_xor]++;
        
        }
        
        return result;
        
    }
};