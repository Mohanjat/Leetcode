class Solution {
public:
    
    bool solve(vector<vector<int>>& grid, int i, int j){
        
        vector<int> v(10,0);
         
        int sum = 0;
        
        int check = 3;
        int dumycol = j;
        
        while(check--){
            sum += grid[i][dumycol];
            dumycol++;
        }
        
        int rowSum = 0;
        
        for(int row = i; row<i+3; row++){
            int rowSum = 0;
             for(int col = j; col < j+3; col++){
               if(grid[row][col] < 10)v[grid[row][col]]++;
               rowSum += grid[row][col];
             }
            if(rowSum != sum) return false;
            
            // cout<<"val of rowSum "<<rowSum<<endl;
        }
        
         for(int col = j; col<j+3; col++){
            int colSum = 0;
             for(int row = i; row < i+3; row++){
                if(grid[row][col] < 10)v[grid[row][col]]++;  
               colSum += grid[row][col];
             }
            if(colSum != sum) return false;
                         // cout<<"val of colSum "<<colSum<<endl;

        }
        
        int col = j;
        int row = i;
        
        int cnt = 3;
        int dSum = 0;
        while(cnt--){
             if(grid[row][col] < 10)v[grid[row][col]]++;
            dSum += grid[row][col];
            row++;
            col++;
        }

        if(dSum != sum) return false;
        
        col = j+2;
        row = i;
        
        cnt = 3;
        dSum = 0;
        
        while(cnt--){
             if(grid[row][col] < 10)v[grid[row][col]]++;
            dSum += grid[row][col];
            col--;
            row++;
        }
        
        if(dSum != sum) return false;
        
        
        for(int i=1; i<10; i++){
            if(v[i] == 0) return false;
        }        
        return true;
        
    }
    
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for(int i=0; i<row-2; i++){
            for(int j=0; j<col-2; j++){
                
                if(solve(grid,i,j)){
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
};