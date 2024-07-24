class Solution {
public:
    
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums){
        
        vector<pair<int,int>> v;
        
        
        for(int i=0; i<nums.size(); i++){
            
            long long mappedVal = 0;
            
            long long num = nums[i];        
        
            int j = 0;
            
            while(true){
                
                long long digit = num % 10;
                
                long long value = mapping[digit];  
                
                mappedVal += value * (pow(10,j));;
                
                j++;
                
                num /= 10;
                
            //  cout<<"val of "<<value<<" for nums "<<nums[i]<<endl;
                
                if(num == 0) break;
                
            }
            
          //  cout<<mappedVal<<endl;
            
            v.push_back({mappedVal,i});
            
        }
        
        sort(v.begin(),v.end());
        
        vector<int> ans;
        
        for(int i=0; i<v.size(); i++){
            ans.push_back(nums[v[i].second]);
        }
        
        return ans;
        
    }
};