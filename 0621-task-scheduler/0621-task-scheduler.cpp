// class Node{
//     public:
//     char ch;
//     int count;
    
//     Node(char c, int cnt){
//         ch = c;
//         count = cnt;
//     }
// };

// class comparator{
//     public:
//     bool operator()(Node*a, Node*b){
//         return a->count < b->count;
//     }
// };

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> map;
        priority_queue<pair<int, char>> maxHeap;
        int ans = 0;

        for (char task : tasks) {
            map[task]++;
        }

        for (auto& it : map) {
            maxHeap.push({it.second, it.first});
        }

        while (!maxHeap.empty()) {
            int dummy = n + 1;
            vector<pair<int, char>> temp;

            while (dummy > 0 && !maxHeap.empty()) {
                auto task = maxHeap.top();
                maxHeap.pop();

                task.first--;
                if (task.first > 0) {
                    temp.push_back(task);
                }

                ans++;
                dummy--;
            }

            for (auto& t : temp) {
                maxHeap.push(t);
            }

            if (!maxHeap.empty()) {
                ans += dummy;
            }
        }

        return ans;
    }
};