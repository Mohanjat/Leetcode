class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        for(int i=0; i<sandwiches.size(); i++){
            int j = 0;
            while(j<students.size()){
                if(students[j] == sandwiches[i]){
                    int ind = 0;
                    while(ind < j){
                        int temp = students[0];
                        students.erase(students.begin());
                        students.push_back(temp);
                        ind++;
                    }
                    if(j == students.size()-1) j -= 1;
                    students.erase(students.begin());
                    break;
                }
                else{
                    j++;
                }
            }
    
            if(j >= students.size()){
                return students.size();
            }
        }
        
        return 0;
    }
};