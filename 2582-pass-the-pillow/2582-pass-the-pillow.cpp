class Solution {
public:
    int passThePillow(int n, int time){
        
        int remaining = time / (n-1);
        int timeLeft = time - (n-1)*remaining;
        
        if(remaining % 2 == 0){
            //means need to paas pillow from start to end
            return timeLeft+1;
        }
        else{
            //paas the pillow from end to start
            return n - (timeLeft);
        }

    }
};