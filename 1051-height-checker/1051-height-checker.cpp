class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        vector<int> temp(heights.size());
        
        copy(heights.begin(),heights.end(),temp.begin());
        
        sort(temp.begin(),temp.end());
        
        int ans = 0;
        
        for(int i=0; i<heights.size(); i++){
            if(heights[i] != temp[i]) ans++;
        }
        return ans;
    }
};