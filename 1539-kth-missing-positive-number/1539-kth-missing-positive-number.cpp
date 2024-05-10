class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        //Approach#2 Binary Search
        
        int s = 0;
        int e = arr.size()-1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            int missing = arr[mid]-(mid+1);
            if(missing<k){
               //search in the right part
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        
        return k+e+1; //return k+s;
        
        
        
//         int cnt = 0;
//         int firstEle = arr[0];
//         int element = 1;
//         while(element<firstEle){
//             cnt++;
//             if(cnt == k){
//                 return element;
//             }
//             element++;
//         }
        
//         for(int i=1; i<arr.size(); i++){
//             int ele = arr[i-1]+1;
//             while(ele < arr[i]){
//                 cnt++;
//                 if(cnt == k) return ele;
//                 ele++;
//             }
        
//         }
        
//         //if cnt == 0 means array is having all the elements
//         int newEle = arr[arr.size()-1]+1;
//         while(true){
//             cnt++;
//             if(cnt == k) return newEle;
//             newEle++;
//         }
        
//         return 0;
    }
};