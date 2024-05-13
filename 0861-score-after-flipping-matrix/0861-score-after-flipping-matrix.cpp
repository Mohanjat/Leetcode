class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        //Follow two simple rules
        //1- Flip the row if first element in that row is 0
        //2- Toggle a column if no of 0's > no of 1's in that colmun
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++){
            //set first column to 1
            if(grid[i][0] == 0){
                //toggle the complete row
                for(int j=0; j<m; j++){
                    grid[i][j] = 1-grid[i][j];
                }
            }
        }
        
        //check the columns
        for(int j=1; j<m; j++){
            int cntZero = 0;
            for(int i=0; i<n; i++){
                if(grid[i][j] == 0) cntZero++;
            }
            
            int cntOne = n-cntZero;
            
            if(cntZero>cntOne){
                //toggle that column becuase we want maximum 1's
                for(int i=0; i<n; i++){
                    grid[i][j] = 1-grid[i][j];
                }
            }
        }
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                ans += (pow(2,m-j-1)) * grid[i][j];
            }
            
        }
        
        return ans;
        
    }
};