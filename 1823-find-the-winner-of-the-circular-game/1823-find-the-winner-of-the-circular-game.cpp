class Solution {
public:
    int findTheWinner(int n, int k){
        
        vector<int> friends;
        int i = 1;
        while(n--){
            friends.push_back(i);
            i++;
        }
        
        int currPos = 0;
        
        while(friends.size() > 1){
            //need to delete this position 
            int deletePos = (currPos + k-1) % friends.size();
            
            auto it = friends.begin() + deletePos;
            
            friends.erase(it);
            
            //update the currPos
            if(deletePos == friends.size()){
                currPos = 0;
            }
            else{
                currPos = deletePos;
            }
        }
        
        return friends[0];
    }
};