class Solution {
public:
    
    bool isPossible(long long mid, vector<int>&weights,int days){
        
        for(int i=0; i<weights.size(); i++){
            
            if(days == 0) return false;
            
            long long sum = 0;
            
            while(i<weights.size() && sum<mid){
                sum += weights[i];
                //sum mid se bda ho gya mtlb last wala jo sum tha wha tk hi possible h bs
                if(sum > mid){
                    i--;
                    days--;
                    break;
                }
                //agr sum == mid to weight possible h 
                if(sum == mid){
                    days--;
                    break;
                }
                i++;
            }
        }
        
        return true;
        
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        //Binary Search Problem and we have search space
        //Search Space == max Weights to Sum of Weights
       //point is== bhai max weight ko 1 day m to km se km lekr jaana pdega hi usse 
        //km weight to ho hi nhi skta h
        //aur agr worst case senerio is that ,, agr hmaare paas ek hi din ho to
        // saare weights ek hi din shift krna pdega than that's it
        
        
        int maxi = INT_MIN;
        int sum = 0;
        for(int i=0; i<weights.size(); i++){
            maxi = max(maxi,weights[i]);
            sum += weights[i];
        }
        
        long long s = maxi;
        long long e = sum;
        long long ans = INT_MAX;
        
        while(s<=e){
            long long mid = s+(e-s)/2;
            bool check = isPossible(mid,weights,days);
            
            if(check){
                //agr answer possible h to answer ko store kr lo and check for better ans
                if(ans > mid) ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        
        return ans;
    }
};