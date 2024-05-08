class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> maxHeap;
        
        for(auto i:score){
            maxHeap.push(i);
        }
        
        unordered_map<int,int> mp;
        
        for(int i=0; i<score.size(); i++){
            mp[score[i]] = i;
        }
        
        vector<string> ans(score.size(),"");
        
        int cnt = 1;
        
        while(!maxHeap.empty()){
            
            int index = mp[maxHeap.top()];
            
            if(cnt == 1){
                ans[index] = "Gold Medal";
            }
            else if(cnt == 2){
                ans[index] = "Silver Medal";
            }
            else if(cnt == 3){
                ans[index] = "Bronze Medal";
            }
            else{
                ans[index] = to_string(cnt);
            }
            cnt++;
            maxHeap.pop();
        }
        return ans;
    }
};