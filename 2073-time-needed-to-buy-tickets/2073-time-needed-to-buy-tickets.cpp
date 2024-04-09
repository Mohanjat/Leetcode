class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        //optimal method
        
        int sec = tickets[k];
        
        for(int i=0; i<k; i++){            
            if(tickets[i] >= tickets[k]){
                sec += tickets[k];
            }
            else{
                sec += tickets[i];
            }
        }
        
        for(int i=k+1; i<tickets.size(); i++){
            if(tickets[i] >= tickets[k]){
                sec += tickets[k]-1;
            }
            else{
                sec += tickets[i];
            }
        }
        
        return sec;
        
        
//         int sec = 0;
        
//         while(true){
//             bool check = false;
//             for(int i=0; i<tickets.size(); i++){
//                 if(tickets[i] == 0) continue;
//                 tickets[i] -= 1;
//                 sec++;
//                 if(i == k && tickets[i] == 0){
//                     check = true;
//                     return sec;
//                 }
//             }
//         }
        
//         return 0;
        
    }
};