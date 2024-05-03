class Solution {
public:
    int compareVersion(string version1, string version2) {
        //compare each version of version1 and version2
        
        int i=0;
        int j=0;
        
        while(i<version1.length() && j<version2.length()){
            string a;
            string b;
            while(i<version1.length() && version1[i] != '.'){
                a.push_back(version1[i]);
                i++;
            }
            if(i<version1.length()) i++;
            
            while(j<version2.length() && version2[j] != '.'){
                b.push_back(version2[j]);
                j++;
            }
            
            if(j<version2.length()) j++;
            
            //campare both strings;
            int v1 = stoi(a);
            int v2 = stoi(b);
            if(v1>v2) return 1;
            if(v2>v1) return -1;
            
        }
        
        while(i<version1.length()){
            string a;
            while(i<version1.length() && version1[i] != '.'){
                a.push_back(version1[i]);
                i++;
            }
            if(i<version1.length()) i++;
            
           int v1 =stoi(a);
           if(v1>0) return 1;
        }
        
          while(j<version2.length()){
            string b;
            while(j<version2.length() && version2[j] != '.'){
                b.push_back(version2[j]);
                j++;
            }
            if(j<version2.length()) j++;
            
            int v2 = stoi(b);
            if(v2>0) return -1;
        }
        
        return 0;
    }
};