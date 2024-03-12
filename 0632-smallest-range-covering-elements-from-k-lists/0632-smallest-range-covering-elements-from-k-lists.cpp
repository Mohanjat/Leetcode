class Info{
  public:
    int val;
    int row;
    int col;
    
    Info(int v,int r,int c){
        val = v;
        row = r;
        col = c;
    }
};

class comparator{
    public:
    bool operator()(Info*a,Info*b){
        return a->val > b->val;
    }
};

class Solution {
public:
    
    vector<int>  rangeOfElements(vector<vector<int>>& nums,int row){
        //mini heap
        priority_queue<Info*,vector<Info*>,comparator> pq;
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        //process first k elements
        for(int i=0; i<row; i++){
            //create a new node of all the first k elements
            Info* newInfo = new Info(nums[i][0],i,0);
            maxi = max(maxi,nums[i][0]);
            mini = min(mini,nums[i][0]);
            pq.push(newInfo);
        }
        //now we have a min heap having first k elements
        //now process remaining n-k elements
        vector<int>ans{mini,maxi};
        
        while(!pq.empty()){
            //take a minimum element of the pq
            Info* element = pq.top();
            pq.pop();
            
            int topEle = element->val;
            int topRow = element->row;
            int topCol = element->col;
            
            //now we have max and min element of current k elements;
            //here is the logic of camparing two ranges
        
            if(pq.size() == row-1){
               
                int prevRange = ans[1]-ans[0];
                int currRange = maxi- topEle;
                if(prevRange > currRange){
                    //update the range
                    ans[0] = topEle;
                    ans[1] = maxi;
                }
                else if(prevRange == currRange){
                      if(ans[0]>topEle){
                        //consider currRange as minimum range
                        ans[0] = topEle;
                        ans[1] = maxi;  
                       }
                }
            }
            
            //issue in this line
            vector<int> currArr = nums[topRow];
            
            int currRowSize = currArr.size();
            
            if(topCol+1 < currRowSize){
                //then can procedd further
                //now insert a new info data in the mini heap
                Info* temp = new Info(nums[topRow][topCol+1], topRow,topCol+1);
                maxi = max(maxi,nums[topRow][topCol+1]);
                pq.push(temp);
            }
            
        }
        
        return ans;
        
    }
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int row = nums.size();
        
        return rangeOfElements(nums,row);
        
    }
};