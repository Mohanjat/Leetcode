class Solution {
public:
    
    bool isPossible(vector<int>&bloomDay,int mid, int m,int k){
    
        long long temp = 0;
        
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] - mid <= 0){
                //means floower is bloomed
                //we can use it
                temp++;
            }
            else{
                //means floower is not bloomed 
                //and we have to move forward and adjacent floower is also break
                temp = 0;
            }
            //agr temp == k h to hum ek bouquet bana skte h
            if(temp == k){
                m--;
                //now to check for another k adjacent elements
                temp = 0;
            }
            if(m == 0) return true;
        }
        
        //agr k == 0 iska mtlb h ki we can make bouquets
        return m <= 0;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        //this is the kind of binary search problem where 
        //ans is definetly between the min value of the bloomDay and maxValue of bloomDay
        //we have search space here and apply binary search 
        
        if(bloomDay.size()/k < m) return -1;
        
        long long s = INT_MAX;
        long long e = INT_MIN;
        
        for(int i=0; i<bloomDay.size(); i++){
            if(s > bloomDay[i]){
                s = bloomDay[i];
            }
            if(e < bloomDay[i]){
                e = bloomDay[i];
            }
        }
        
        long long ans = 0;
        
        while(s<=e){
            long long mid = s + (e-s)/2;
            
            bool check = isPossible(bloomDay,mid,m,k);
            
            if(check){
                //than store the answer and check for better answer
                ans = mid;
                e = mid-1;
            }
            else{
                //bouquets banana possible nhi h aur wait krna pdega
                //means number of days will increase here
                s = mid+1;   
            }
        }
                
        return ans;
    }
};