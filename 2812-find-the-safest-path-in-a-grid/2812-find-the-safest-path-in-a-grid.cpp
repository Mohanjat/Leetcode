class Solution {
public:
    
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    
    bool checkForValid(vector<vector<int>> &manHattenDis,int mid,int n){
        
        if(manHattenDis[0][0] == -1 || manHattenDis[0][0] < mid) return false;
        
        vector<vector<int>> visited(n,vector<int>(n,0));
        
        queue<pair<int,int>> q;
        
        q.push({0,0});
        visited[0][0] = 1;
        
        while(!q.empty()){
            int curr_i = q.front().first;
            int curr_j = q.front().second;
            q.pop();
            
            //agr destination pr phuch gye h to true return kr do nhi to aage bdo
            if(curr_i == n-1 && curr_j == n-1) return true;
            
            for(vector<int>&dir : directions){
                int new_i = curr_i+dir[0];
                int new_j = curr_j+dir[1];
                //check for invalid cell
                if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= n || visited[new_i][new_j] == 1 ||                                        manHattenDis[new_i][new_j] < mid){
                        continue;
                }
                
                q.push({new_i,new_j});
                visited[new_i][new_j] = 1;
            }
        }
        return false;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        //pre-calculate ManHattan Distance for each cell
        //Apply binary search on Safest factor
        // s == 1 and e = infinite and let say mid is == x
        //now reach (0,0) to (row-1)(col-1) if there is a path in which all cells
        //have value >= x
        
        
        //Step1: pre-calculation of the ManHatten Distance
        int n = grid.size();
        
        //vector for storing manHattan distance of each cell
        vector<vector<int>>manHattenDis(n,vector<int>(n,-1));
        vector<vector<int>> visited(n,vector<int>(n,0));
        
        //creating a queue for bfs
        queue<pair<int,int>>q;
        
        //push all the thieves in the queue
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                  q.push({i,j});
                  visited[i][j] = 1;    
                }  
            }
        }
        
        //now calculate manHattan dist
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr_i = q.front().first;
                int curr_j = q.front().second;
                q.pop();
                //now push the distance in the curr cell 
                manHattenDis[curr_i][curr_j] = level;
                
                //now traverse all the neighbours of the curr cell
                for(vector<int>&dir : directions){
                    int new_i = curr_i+dir[0];
                    int new_j = curr_j+dir[1];
                    //check for invalid cell
                    if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= n || visited[new_i][new_j] == 1){
                        continue;
                    }
                    //push the neighbhour in the queue
                    q.push({new_i,new_j});
                    //and mark visited
                    visited[new_i][new_j] = 1;
                }
            }
            //increase the level by 1
            level++;
        }
        
        
        //Step2:- apply binary search of the safest factor 
        int s = 0;
        int e = 400; ///uper limit of n given in the problem
        int ans = 0;
        
        while(s<=e){
            
            int mid = s + (e-s)/2;
            
            if(checkForValid(manHattenDis,mid,n)){
                //agr koi esa path possible h jiske ander saari values mid se choti h ya brabr h to ans to update kr do
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            
        }
        return ans;
    }
};




// class Solution {
// public:
    
//     bool isPossible(vector<vector<int>>& grid,vector<vector<int>>& visited,int row,int col,int i,int j){
//         if(i<0 || i>=row || j<0 || j>=col || visited[i][j] == 1 || grid[i][j] == 1) return false;
//         return true;
//     }
    
//     int checkManhattanDis(int i,int j,vector<pair<int,int>> &ones){
//         int dis = INT_MAX;
//         for(int k=0; k<ones.size(); k++){
//             int currDis = abs(ones[k].first - i) + abs(ones[k].second-j);
//             dis = min(dis,currDis);
//         }
//         return dis;
//     }
    
//     void solve(vector<vector<int>>& grid,vector<vector<int>>& visited,int row,int col,int i,int j,int &ans,int currDis,vector<pair<int,int>> &ones){
//         //base case
//         if(i >= row-1 && j >= col-1){
//             ans = max(ans,currDis);
//             return;
//         }
        
//         if(!(isPossible(grid,visited,row,col,i-1,j)) && !(isPossible(grid,visited,row,col,i+1,j)) &&
//            !(isPossible(grid,visited,row,col,i,j+1)) && !(isPossible(grid,visited,row,col,i,j-1))){
//             return;
//         }
        
//         //up
//         if(isPossible(grid,visited,row,col,i-1,j)){
//             int manHatt = checkManhattanDis(i-1,j,ones);
//             visited[i-1][j] = 1;
//             solve(grid,visited,row,col,i-1,j,ans,min(manHatt,currDis),ones);
//             visited[i-1][j] = 0;
//         }
//         //dawn
//         if(isPossible(grid,visited,row,col,i+1,j)){
//             int manHatt = checkManhattanDis(i+1,j,ones);
//             visited[i+1][j] = 1;
//             solve(grid,visited,row,col,i+1,j,ans,min(manHatt,currDis),ones);
//             visited[i+1][j] = 0;
//         }
//         //right
//         if(isPossible(grid,visited,row,col,i,j+1)){
//             int manHatt = checkManhattanDis(i,j+1,ones);
//             visited[i][j+1] = 1;
//             solve(grid,visited,row,col,i,j+1,ans,min(manHatt,currDis),ones);
//             visited[i][j+1] = 0;
//         }
//         //left
//         if(isPossible(grid,visited,row,col,i,j-1)){
//             int manHatt = checkManhattanDis(i,j-1,ones);
//             visited[i][j-1] = 1;
//             solve(grid,visited,row,col,i,j-1,ans,min(manHatt,currDis),ones);
//             visited[i][j-1] = 0;
//         }
        
//     }
    
//     int maximumSafenessFactor(vector<vector<int>>& grid){
        
//         int row = grid.size();
//         int col = grid[0].size();
        
//         if(grid[0][0] == 1 || grid[row-1][col-1] == 1) return 0;
        
//         vector<pair<int,int>> ones;
        
//         for(int i=0; i<row; i++){
//             for(int j=0; j<col; j++){
//                 if(grid[i][j] == 1){
//                     ones.push_back({i,j});
//                 }
//             }
//         }
        
//         vector<vector<int>> visited(row,vector<int>(col,0));
//         visited[0][0] = 1;
//         int ans = INT_MIN;
//         int currDis = INT_MAX;
        
//         int manHatt = checkManhattanDis(0,0,ones);
        
//         solve(grid,visited,row,col,0,0,ans,min(currDis,manHatt),ones);
        
//         return ans == INT_MIN ? 0 : ans;
//     }
// };