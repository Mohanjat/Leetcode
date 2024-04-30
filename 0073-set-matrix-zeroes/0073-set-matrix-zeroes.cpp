class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix){
        
        int row = matrix.size();
        int col = matrix[0].size();
        
       set<pair<int,int>> st;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 0){
                    st.insert({i,j});
                }
            }
        }
        
        //now we have all the values of rows and cols need to be replace by zeros
        
        for(auto it:st){
            int currRow = it.first;
            int currCol = it.second;
            //making currRow to zero
            for(int i=0; i<col; i++){
                matrix[currRow][i] = 0;
            }
            //making currCol to zero
            for(int i=0; i<row; i++){
                matrix[i][currCol] = 0;
            }
        }
        
    }
};