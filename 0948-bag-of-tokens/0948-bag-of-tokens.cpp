class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        //we have two options - Face UP and Face-Down
        
        sort(tokens.begin(), tokens.end());
        
        int i=0;
        int j=tokens.size()-1;
        int score = 0;
        vector<bool> visited(tokens.size(),false);
        
        //first of all atleast one score kr lo
        while(i<tokens.size()){
            if(power >= tokens[i]){
                score++;
                power -= tokens[i];
                visited[i] = true; 
                break;
            }
            i++;
        }
        
        if(score == 0) return 0;
        int ans = INT_MIN;
        ans = max(ans,score);
        //wapis start kr lo
        i = 0;
        cout<<"score is "<<score<<endl;
        while(i<j){
            //face-up
            //if power is efficient to increase score then increase it
            while(power >= tokens[i]){
                if(visited[i] == true){
                    i++;
                    continue;
                }
                score++;
                power -= tokens[i];
                visited[i] = true;
                i++;
            }
            ans = max(ans,score);
            //face down
            if(score != 0){
                if(visited[j] == true){
                    j--;
                    continue;
                }
                score--;
                power += tokens[j];
                visited[j] = true;
                j--;
            }
          
        }
        return ans;
    }
};