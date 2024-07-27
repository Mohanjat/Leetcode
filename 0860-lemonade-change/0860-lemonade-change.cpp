class Solution {
public:
    bool lemonadeChange(vector<int>& bills){
       
        int five = 0;
        int ten = 0;
        
        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5){
                five++;
            }
            else if(bills[i] == 10){
                //we should a 5 bill in the map to give change
                 if(five == 0) return false;
                
                five--;
                ten++;
            }
            else{
                //bills == 20
                
                if(ten > 0 && five > 0){
                    ten--;
                    five--;
                }
                else if(five >= 3) {
                    five -= 3;
                }
                else{
                    return false;
                }
            }
        }
        
        return 1;
    }
};