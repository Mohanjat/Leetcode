class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        vector<vector<int>> maxLocal(n-2,vector<int>(n-2,0));
        int maxi = INT_MIN;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                maxi = max(maxi,grid[i][j]);
            }
        }
        
        maxLocal[0][0] = maxi;
        
        for(int row=0; row<=n-3; row++){
            for(int col=0; col<=n-3; col++){
                
           
            //now iterate over 3*3 matrix
                maxi = INT_MIN;
                for(int i=row; i<row+3; i++){
                    for(int j=col; j<col+3; j++){
                        maxi = max(maxi,grid[i][j]);
                    }
                }
                
                maxLocal[row][col] = maxi;
            }
        }
        return maxLocal;        
    }
};