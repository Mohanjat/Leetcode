class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit){
        //Gready Approach
        //Intituaion is that ,, sbse mote aadmi ko sbse phle bhej do 
        //using two pointer
        
        sort(people.begin(),people.end());
        
        int i=0;
        int j=people.size()-1;
        int boat = 0;
        
        while(i<=j){
            if(people[i]+people[j] <= limit){
                i++;
                j--;
                boat++;
            }
            else{
                j--;
                boat++;
            }
        }
        return boat;
    }
};