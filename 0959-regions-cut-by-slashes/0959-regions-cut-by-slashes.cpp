class Solution {
public:
    
    void findRegion(vector<vector<int>>& matrix, int i, int j){
        //check for outof bond condition
        if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j] == 1){
            return;
        }
        
        matrix[i][j] = 1; //mark as visited
        
        findRegion(matrix,i+1,j);
        findRegion(matrix,i-1,j);
        findRegion(matrix,i,j+1);
        findRegion(matrix,i,j-1);
    }
    
    int regionsBySlashes(vector<string>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        int regions = 0;
        
        //intialize a matrix 
        //let '/' as 3*3 matrix
        
        // (//) is recognize as only /
        
        vector<vector<int>> matrix(row*3,vector<int>(col*3,0));
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '/'){
                    matrix[i*3][j*3+2] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3] = 1;
                }
                else if(grid[i][j] == '\\'){
                     matrix[i*3][j*3] = 1;
                     matrix[i*3+1][j*3+1] = 1;
                     matrix[i*3+2][j*3+2] = 1;
                }
            }
        }
        
        ///apply dfs same as find isaland 
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                cout<<matrix[i][j]<<" ";
                if(matrix[i][j] == 0){
                    findRegion(matrix,i,j);
                    regions++;
                }
            }
            cout<<endl;
        }
        
        return regions;
    }
};