class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        
        for(auto i:arr1){
            mp[i]++;
        }
        
        vector<int> ans;
        
        for(int i=0; i<arr2.size(); i++){
            int occ = mp[arr2[i]];
            while(occ--){
                ans.push_back(arr2[i]);
            }
            mp.erase(arr2[i]);
        }
        vector<int> temp;
        
        for(auto i:mp){
            int occ = i.second;
            while(occ--){
                temp.push_back(i.first);
            }
        }
        
        sort(temp.begin(),temp.end());
        
        for(int i=0; i<temp.size(); i++){
            ans.push_back(temp[i]);
        }
        
        return ans;
        
    }
};