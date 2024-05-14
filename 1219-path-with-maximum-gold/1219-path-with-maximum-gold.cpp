class Solution {
public:
    
    
    bool isPossible(vector<vector<int>>& grid,vector<vector<int>>&visited,int i, int j,int row,int col){
        if(i<0 || j<0 || i>= row || j>=col || visited[i][j] == 1 || grid[i][j] == 0) return false;
        return true;
    }
    
    void getGold(vector<vector<int>>& grid,vector<vector<int>>&visited,int sum,int row,int col,int i,int j,int &ans){
        
        //agr koi bhi move possible nhi h to return kr jao;
        if(!(isPossible(grid,visited,i-1,j,row,col)) && !    (isPossible(grid,visited,i+1,j,row,col)) && !(isPossible(grid,visited,i,j-1,row,col)) &&
          !(isPossible(grid,visited,i,j+1,row,col))){
            ans = max(ans,sum);
            return;
        }
        
        //we are at possition and we have 4 moves
        //up
        if(i-1>=0 && visited[i-1][j] != 1 && grid[i-1][j] != 0){
            //it means it is possible move
            visited[i-1][j] = 1;
            getGold(grid,visited,sum+grid[i-1][j],row,col,i-1,j,ans);
            visited[i-1][j] = 0;
        }
        //down
        if(i+1<row && visited[i+1][j] != 1 && grid[i+1][j] != 0){
            //it means it is possible move
            visited[i+1][j] = 1;
            getGold(grid,visited,sum+grid[i+1][j],row,col,i+1,j,ans);
            visited[i+1][j] = 0;
        }
        //left
        if(j-1>=0 && visited[i][j-1] != 1 && grid[i][j-1] != 0){
            //it means it is possible move
            visited[i][j-1] = 1;
            getGold(grid,visited,sum+grid[i][j-1],row,col,i,j-1,ans);
            visited[i][j-1] = 0;
        }
        //right
        if(j+1<col && visited[i][j+1] != 1 && grid[i][j+1] != 0){
            //it means it is possible move
            visited[i][j+1] = 1;
            getGold(grid,visited,sum+grid[i][j+1],row,col,i,j+1,ans);
            visited[i][j+1] = 0;
        }
        
    }
    
    int getMaximumGold(vector<vector<int>>& grid){
        
        //brute force solution
        //start with every element and calculate the answer
        
        int row = grid.size();
        int col = grid[0].size();
        
        int maxi = INT_MIN;
        
       //find sum for every element 
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 0) continue;
                vector<vector<int>> visited(row,vector<int>(col,0));
                visited[i][j] = 1;
                int sum = grid[i][j];
                int ans = INT_MIN;
                getGold(grid,visited,sum,row,col,i,j,ans);
                maxi = max(maxi,ans);
            }
        }
        
        return maxi == INT_MIN ? 0 : maxi;
    }
};