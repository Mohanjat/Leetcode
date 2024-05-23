class Solution {
public:
    int beautySum(string s) {
        
        int i = 0;
        
        int ans = 0;
                
        while(i<s.length()){
            int j = i;
            unordered_map<char,int> mp;
            int maxi = INT_MIN;
            
            while(j<s.length()){
                
                int mini = INT_MAX;
                
                mp[s[j]]++;
                
                maxi = max(maxi,mp[s[j]]);
                
                for(auto &it : mp){
                    mini = min(mini,it.second);
                }
                
                if((mini == INT_MAX) || (mp.size() == 1)){
                    j++;
                    continue;
                }
                
                ans += maxi-mini;
                
                j++;
            }
            
            i++;  
        }
        
        return ans;
        
    }
};