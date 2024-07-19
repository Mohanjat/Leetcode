class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> lucky;
        
        unordered_map<int,int> visited;
        
        for(int i=0; i<m; i++){
            int mini = INT_MAX;
            int col = -1;
            for(int j=0; j<n; j++){
                if(matrix[i][j] < mini){
                    mini = matrix[i][j];
                    col = j;
                }
            }
            
            //we have minimum element of the row
            //now check for-- is this is the max element in the col or not
            //check for already visited col 
            if(visited.find(col) != visited.end()){
                continue;
            }
            
            bool check = true;
            
            for(int k=0; k<m; k++){
                if(matrix[k][col] > mini){
                    check = false;
                    break;
                }
            }
            
            if(check){
                //means its a lucky number
                visited[col]++;  //mark curr col as visited;
                lucky.push_back(mini);
            }
        }
        
        return lucky;
    }
};