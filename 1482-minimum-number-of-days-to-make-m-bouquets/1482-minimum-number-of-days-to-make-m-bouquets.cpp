class Solution {
public:
    
    bool isPossible(int &mid, vector<int>&b, int m,int &k){
        
        for(int i=0; i<b.size(); i++){
            int temp = k;
            
            while(temp != 0 && i<b.size()){
                if(b[i] > mid) break;
                i++;
                temp--;
            }
            
            if(temp == 0){
                i--;
                m--;
            }
            
            if(m == 0) return true;
        }
        
        return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k){
        
         int e = *std::max_element(bloomDay.begin(), bloomDay.end());
         int s = *std::min_element(bloomDay.begin(), bloomDay.end());
        
        int ans = -1;
        
        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(isPossible(mid,bloomDay,m,k)){
                //store the answer
                ans = mid;
                //check for most optimal answer
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        
        return ans;
        
    }
};