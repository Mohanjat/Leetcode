class Solution {
public:
    
    void findSubset(vector<int>&nums,set<vector<int>> &st,int i,vector<int>temp){
        
        if(i>=nums.size()){
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return;
        }
        
        //include
        temp.push_back(nums[i]);
        findSubset(nums,st,i+1,temp);
        temp.pop_back();
        
        //exclude
        findSubset(nums,st,i+1,temp);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        set<vector<int>> st;
        vector<int> temp;
        
        findSubset(nums,st,0,temp);
        
        vector<vector<int>> ans;
        
        for(auto &it:st){
            ans.push_back(it);
        }
        
        return ans;
        
    }
};