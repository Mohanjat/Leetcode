class Solution {
public:
    int pivotInteger(int n) {
        
        int pivot = n/2;
        
        int leftSum = 0;
        int rightSum = 0;
        
        for(int i=1; i<=pivot; i++){
            leftSum += i;
        }
        
        for(int i=pivot; i<=n; i++){
            rightSum += i;
        }
        
        while(leftSum <= rightSum && pivot<=n){
            
            if(rightSum == leftSum) return pivot;
            
            if(leftSum < rightSum){
                int temp = pivot;
                pivot++;
                
                leftSum += pivot;
                rightSum -= temp;
            }
            
        }
        
        return -1;
    }
};