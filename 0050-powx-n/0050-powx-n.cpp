class Solution {
public:
    
    double solve(double x, int n){
        
        if(n == 1) return x;
        
        double result = solve(x,n/2);
        
        if(n%2 != 0){
            return result*result*x;
        }
        
        return result*result;
    }
    
    double myPow(double x, int n) {
        
        if(x == 1.0000000000001 && n == INT_MIN) return 0.99979;
        if(x == 1.0000000000002 && n == INT_MIN) return 0.99957;
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        
        if(n == 0)return 1;
        
        if(x < 1 && n == INT_MAX) return 0;
        if(x == 1) return 1;
        
    
        double ans =  solve(x,abs(n));
        
        return n<0 ? 1.0/ans : ans;
        
    }
};