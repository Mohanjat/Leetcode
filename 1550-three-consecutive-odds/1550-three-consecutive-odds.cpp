class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        int odd = 0;
        
        if(arr.size() < 3) return false;
        
        for(int i=0; i<3; i++){
            if(arr[i]%2 != 0) odd++;    
        }
        
        if(odd == 3) return true;
        int i = 3;
        int j = 0;
        
        while(i<arr.size()){
            
            if(arr[j] % 2 != 0){
                odd--;
            }
            
            if(arr[i] %2 != 0){
                odd++;
            }
            
            j++;
            i++;
            
            if(odd == 3) return true;
            
        }
        
        if(odd == 3) return true;
        
        return false;
        
    }
};