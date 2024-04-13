class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        //this is kind of fixed window size problem
        
        int maxi = INT_MIN;
        int sum = 0;
        //first of all calculate the sum of the first k size window
        for(int i=0; i<k; i++){
            sum += cardPoints[i];
        }
        
        if(k == cardPoints.size()){
            return sum;
        }
        maxi = max(sum,maxi);
        
        int i = 0;
        int j = k-1;
        
        while(k--){
            sum -= cardPoints[j];
            if(i == 0){
                i = cardPoints.size();
            }
            i--;
            sum += cardPoints[i];
            j--;
            //update maxi
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};