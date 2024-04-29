class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        //this is kind of bit manipulation
        //total elements ka xor nikal aur uske k element ki bits se comaper kr lo
        //agr bits same h iska mtlb no need to change anything
        //agr bits different h to ek bits flip krne ki jrurt h to operation++
        
        
        //shortcut
        //totalXor ko k se saath xor nikal lo
        //agr bits same hogi to zero ayega different hogi to one aayega
        //jitne 1 aayenge utne hi operations perform krne padenge
        
        int totalXor = 0;
        
        for(auto i:nums) totalXor ^= i;
        
        int diff = totalXor ^ k;
        
        return __builtin_popcount(diff); // stl for count of 1's, taking logarithmic time complexity
        
    }
};