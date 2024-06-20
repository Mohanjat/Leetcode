class Solution {
public:
    
    bool isPossible(vector<int>& p,int m, int mid){
        
        m--;
        int temp = p[0];
        if(m == 0) return true;
        
        for(int i=1; i<p.size(); i++){
             if(abs(temp - p[i]) >= mid){
                 temp = p[i];
                 m--;
             }    
            
            if(m == 0) return true;
        }
        
        return false;
    }
    
    
    int maxDistance(vector<int>& position, int m) {
        
        // int e = *std::max_element(position.begin(),position.end());
        // int s = *std::min_element(position.begin(),position.end());
        
        sort(position.begin(),position.end());
        
        long long s = 1;
        long long e = position[position.size()-1];
        
        int ans = -1;
        
        while(s<=e){
            
            long long mid = s + (e-s)/2;
            if(isPossible(position,m,mid)){
                //mid is possible and search for maximum answer
                ans = mid;
                s = mid+1;
            }
            else{
                //mid is not possible
                e = mid-1;
            }
            
        }
        
        return ans;
        
    }
};