class Solution {
public:
    string fractionAddition(string exp) {
        
        int nume = 0;
        int deno = 1;
        
        int i =0;
        
        int l = exp.length();
        
        while(i<l){
            
            int currNume = 0;
            int currDeno = 0;
            
            bool isNeg = (exp[i] == '-');
            
            //skip the curr the sign 
            if(exp[i] == '+' || exp[i] == '-'){
                i++;
            }
            
            //build currNume
            while(i<l && isdigit(exp[i])){
                int val = exp[i] - '0';
                currNume = (currNume*10) + val;
                i++;
            }
            
            //skip the '/'
            i++;
            
            if(isNeg == true) currNume *= -1;
            
            while(i<l && isdigit(exp[i])){
                int val = exp[i] - '0';
                currDeno = (currDeno*10) + val;
                i++;
            }
            
            //update the numo and deno
            
            nume = nume*currDeno + currNume*deno;
            deno = deno*currDeno;

        }
        
        cout<<"nume is "<<nume<<endl;
        cout<<"deno is "<<deno<<endl;
        //to ensure irreducible fraction
        int gcd = abs(__gcd(nume,deno)); //ensure it should be possitive
        
        nume /= gcd;
        deno /= gcd;
        
        return to_string(nume) + "/" + to_string(deno);
    }
};