class Solution {
public:
    
    void solve(vector<int> &nums,int k,int i,int &ans,vector<int> &temp){
        //base case
        if(i>=nums.size()){
            // for(int l=0; l<temp.size(); l++){
            //     cout<<temp[l]<<" ";
            // }cout<<endl;
            if(temp.size() == 0) return;
            ans++;
            return;
        }
        
        //include
        //before include check that it is possible or not
        int currSize = temp.size();
        int j = currSize-1;
        bool check = true;
        while(j>=0){
            if(abs(nums[i]-temp[j]) == k){
                //means no need to include the curr value and check further
                check = false;
                break;
            }
            j--;
        }
        
        if(check){
            temp.push_back(nums[i]);
            solve(nums,k,i+1,ans,temp);
            temp.pop_back();
        }
        
        //exclude
        solve(nums,k,i+1,ans,temp);
        
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        
        //using include and exclude
        int ans = 0;
        vector<int>temp;
        solve(nums,k,0,ans,temp);
        return ans;
    }
};