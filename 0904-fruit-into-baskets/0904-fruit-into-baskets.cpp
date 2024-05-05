class Solution {
public:
    int totalFruit(vector<int>& fruits){
        
        pair<int,int> type1;
        pair<int,int> type2;
        
        type1 = {fruits[0],0};
        
        for(int i=1; i<fruits.size(); i++){
            if(fruits[i] != type1.first){
                type2 = {fruits[i],i};
                break;
            }
            type1.second = i;
        }
        
        
        int i = 0;
        int j = type2.second;
        
        int maxFruits = 0;
        
        while(j<fruits.size()){
            
            //we have 3 conditions here
            //first is --  the fruits[j] == type1 fruits 
            if(fruits[j] == type1.first){
                //now update the last occ of the type1 fruit
                type1.second = j;
                maxFruits = max(maxFruits,j-i+1);
                j++;
            }
            //second is -- fruits[j] == type2 fruit ke jaisa ho
            else if(fruits[j] == type2.first){
                //now update the last occ of the type2 fruit
                type2.second = j;
                maxFruits = max(maxFruits,j-i+1);
                j++;
            }
            else{
                //new type ka fruits aa gya h to 
                //type1 aur type2 m jiska index chota hoga useko drop kr denge
                int index1 = type1.second;
                int index2 = type2.second;
                
                if(index1 > index2){
                    //drop the type2 fruit
                    //means update the type of fruit and index
                    type2.first = fruits[j];
                    type2.second = j;
                    //and its time to update i;
                    i = index2+1;
                    maxFruits = max(maxFruits,j-i+1);
                    j++;
                }
                else{
                    //drop type1 fruit
                    type1.first = fruits[j];
                    type1.second = j;
                    i = index1+1;
                    maxFruits = max(maxFruits,j-i+1);
                    j++;
                }
            }
             // cout<<"values  of for type1 "<<type1.first<<" "<<type1.second<<endl;
             // cout<<"values  of for type2 "<<type2.first<<" "<<type2.second<<endl;
        }
        
        return maxFruits;
    }
};