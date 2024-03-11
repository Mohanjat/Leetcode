class Solution {
public:
    string customSortString(string order, string s) {
        
        unordered_map<char,int> map;
        
        for(int i=0; i<s.length(); i++){
            map[s[i]]++;
        }
        
        string ans = "";
        
        for(int i=0; i<order.length(); i++){
            if(map.find(order[i]) != map.end()){
                int cnt = map[order[i]];
                while(cnt!=0){
                    ans += order[i];
                    cnt--;
                }
                map.erase(order[i]);
            }
        }
        
        for(auto i:map){
            int cnt = i.second;
            while(cnt!=0){
                ans += i.first;
                cnt--;
            }
        }
        
        return ans;
        
    }
};