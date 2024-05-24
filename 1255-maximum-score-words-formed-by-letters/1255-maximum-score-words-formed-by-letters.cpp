class Solution {
public:
    
    
    bool isPossible(string s, unordered_map<char,int> &mp){
        int i = 0;
        unordered_map<char,int> tempMp;
        
        for(auto i:s) tempMp[i]++;
        
        for(auto it:tempMp){
            char ch = it.first;
            int occ = it.second;
            
            if(occ > mp[ch]) return false;
        }
        return true;
    }
    
    void solve(vector<string>&words,unordered_map<char,int> &mp, vector<int>&score,int i,int &temp, int&ans){
        
        //base case
        if(i >= words.size()){
            ans = max(ans,temp);
            return;
        }
        
        //include the curr string if it is possible 
        string currStr = words[i];
        
         if(isPossible(currStr,mp)){
                //means we can form currstring using letters
                int k = 0;
                while(k<currStr.length()){
                    //update the curr score
                    temp += score[currStr[k]-'a'];
                    mp[currStr[k]]--;
                    if(mp[currStr[k]] == 0) mp.erase(currStr[k]);
                    k++;
                }
                
                //now explore further
                solve(words,mp,score,i+1,temp,ans);
                
                //backtrack
                k = 0;
                while(k<currStr.length()){
                    //update the curr score
                    temp -= score[currStr[k]-'a'];
                    mp[currStr[k]]++;
                    k++;
                }
         }
        
        //exclude the curr string
         solve(words,mp,score,i+1,temp,ans);
                
        
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score){
        
        //using  Include and Exclude by making all the possible sets
                
        unordered_map<char,int> mp;
        
        for(auto i:letters){
            mp[i]++;
        }
        
        int ans = INT_MIN;
        
        int temp = 0;
        
        solve(words,mp,score,0,temp,ans);
        
        return ans;
    }
};