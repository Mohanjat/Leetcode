class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        long long currTime = customers[0][0]; 
        long long  avgTime = 0;
        
        for(auto i:customers){
            int arrival = i[0];
            int time = i[1];
            
            if(currTime < arrival){
                currTime = arrival + time;
            }
            else{
                currTime += time;
            }
            
            avgTime += currTime - arrival;
        }

        return (double)avgTime/customers.size();
    
    }
};