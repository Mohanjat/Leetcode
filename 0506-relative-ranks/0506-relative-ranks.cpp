class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        //Approach#2 Instead of map and heap using array of size maxElement+1
        
        int maxi = INT_MIN;
        
        for(int i=0; i<score.size(); i++) maxi = max(maxi,score[i]);
        
        vector<int> temp(maxi+1,-1);
        
        for(int i=0; i<score.size(); i++){
            temp[score[i]] = i;
        }
        
        vector<string> ans(score.size(),"");
        
        int cnt = 1;
        
        for(int i=maxi; i>=0; i--){
            
            if(temp[i] == -1) continue;
             
            if(cnt == 1){
                ans[temp[i]] = "Gold Medal";
            }
            else if(cnt == 2){
                ans[temp[i]] = "Silver Medal";
            }
            else if(cnt == 3){
                ans[temp[i]] = "Bronze Medal";
            }
            else{
                ans[temp[i]] = to_string(cnt);
            }
            cnt++;
        }
        
        return ans;
        
        //Approach#1 using Max Heap
        
        
//         priority_queue<int> maxHeap;
        
//         for(auto i:score){
//             maxHeap.push(i);
//         }
        
//         unordered_map<int,int> mp;
        
//         for(int i=0; i<score.size(); i++){
//             mp[score[i]] = i;
//         }
        
//         vector<string> ans(score.size(),"");
        
//         int cnt = 1;
        
//         while(!maxHeap.empty()){
            
//             int index = mp[maxHeap.top()];
            
//             if(cnt == 1){
//                 ans[index] = "Gold Medal";
//             }
//             else if(cnt == 2){
//                 ans[index] = "Silver Medal";
//             }
//             else if(cnt == 3){
//                 ans[index] = "Bronze Medal";
//             }
//             else{
//                 ans[index] = to_string(cnt);
//             }
//             cnt++;
//             maxHeap.pop();
//         }
//         return ans;
        
    }
};