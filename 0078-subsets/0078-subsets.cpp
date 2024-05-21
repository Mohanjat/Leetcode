class Solution {
public:
    
    void solve(vector<int>&nums,int i,set<vector<int>> &st,vector<int> temp){
        
        if(i>=nums.size()){
            st.insert(temp);
            return;
        }
        //include 
        temp.push_back(nums[i]);
        solve(nums,i+1,st,temp);
        //backtrack
        temp.pop_back();
        //exclude
        solve(nums,i+1,st,temp);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> st;
        
        solve(nums,0,st,temp);
        
        for(auto i:st){
            ans.push_back(i);
        }
        return ans;
    }
};