class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int sec = 0;
        
        while(true){
            bool check = false;
            for(int i=0; i<tickets.size(); i++){
                if(tickets[i] == 0) continue;
                tickets[i] -= 1;
                sec++;
                if(i == k && tickets[i] == 0){
                    check = true;
                    return sec;
                }
            }
        }
        
        return 0;
        
    }
};