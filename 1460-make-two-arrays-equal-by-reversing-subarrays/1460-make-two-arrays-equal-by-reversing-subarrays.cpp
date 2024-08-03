class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr){
        unordered_map<int,int> mp;
        
        for(auto i:arr){
            mp[i]++;
        }
        
        for(auto i:target){
            if(mp.find(i) == mp.end()){
                return false;
            }
            else{
                mp[i]--;
                if(mp[i] == 0) mp.erase(i);
            }
        }
        
        return mp.size() == 0 ? true:false;
    }
};