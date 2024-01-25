class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

        //try it by using map

        int sum = 0;
        unordered_map<char,int> map;

        for(auto i:stones){
            map[i]++;
        }

        for(auto i:map){
            if(jewels.find(i.first) != string::npos){
                sum += i.second;
            }
        }

        return sum;

        // int cnt = 0;

        // for(int i=0; i<jewels.length(); i++){
        //     for(int j=0; j<stones.length(); j++){
        //         if(jewels[i] == stones[j]){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
    }
};