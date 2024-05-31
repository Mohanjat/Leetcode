class Solution {
public:
    
    void solve(int &k,int &n, vector<int>temp,set<vector<int>>&st,int i,int sum,vector<int>&visited){
        
        if(i == k){
            if(sum == n){
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            return;
        }
        
        //for every possition i have 9 options
        for(int j=1; j<=9; j++){
            if(visited[j] == 1) continue;
            temp.push_back(j);
            visited[j] = 1;
            solve(k,n,temp,st,i+1,sum+j,visited);
            temp.pop_back();
            visited[j] = 0;
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n){
        set<vector<int>> st;
        
        vector<int>temp;
        
        vector<int>visited(10,0);
        
        solve(k,n,temp,st,0,0,visited);
        
        vector<vector<int>> ans;
        
        for(auto &it:st){
            ans.push_back(it);
        }
        
        return ans;
    }
};