class Solution {
public:
    
    void solve(vector<int> &nums,int k,int i,int &ans,unordered_map<int,int> &mp){
        //base case
        if(i>=nums.size()){
            // for(int l=0; l<temp.size(); l++){
            //     cout<<temp[l]<<" ";
            // }cout<<endl
            if(mp.size() == 0) return;
            ans++;
            return;
        }
        
        //include
        //before include check that it is possible or not
        bool check = true;
        if((mp.find(nums[i]+k) != mp.end()) || (mp.find(nums[i]-k) != mp.end())){
            //means the curr element is not possible
            check = false;
        } 
        
        if(check){
            mp[nums[i]]++;
            solve(nums,k,i+1,ans,mp);
            mp[nums[i]]--;
            if(mp[nums[i]] == 0) mp.erase(nums[i]);
        }
        
        //exclude
        solve(nums,k,i+1,ans,mp);
        
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        
        //using include and exclude
        int ans = 0;
        unordered_map<int,int>mp;
        solve(nums,k,0,ans,mp);
        return ans;
    }
};