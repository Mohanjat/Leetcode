class Solution {
public:
    
    bool solve(long long mid,vector<int> piles,long long h){
        
        long long val = 0;
        
        for(int i=0; i<piles.size(); i++){
            val += ceil(piles[i] / double(mid));    
        }
        
        return val <= h;

    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        //check for maximum element 
        long long e = INT_MIN;
        for(auto i:piles){
            if(i>e){
                e = i;
            }
        }
       
        long long s = 1;
        
        long long k = INT_MAX;
        
        while(s<=e){
            long long mid = s + (e-s)/2;
            
            bool check = solve(mid,piles,h);
            
            //if mid is a valid answer than update k 
            if(check) k = min(k,mid);
            
            //if mid is valid answer than check for better answer
            if(check){
                e = mid-1;
            }
            else{
                //number banans eat per hour should be increased
                s = mid+1;
            }
            
        }
        
        return k;
    }
};