class MedianFinder {
public:
    
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>, greater<int>> minHeap;
    
    double median;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size() == minHeap.size()){
            
            if(num > median){
                //right m jao
                minHeap.push(num);
                median = minHeap.top();
            }
            else{
                //left m jao
                maxHeap.push(num);
                median = maxHeap.top();
            }
            
        }
        else if(maxHeap.size() > minHeap.size()){
            
                if(num > median){
                    //right m jao
                    minHeap.push(num);
                    median = (minHeap.top()+maxHeap.top())/2.0;
                }
                else{
                   int top = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(top);
                    maxHeap.push(num);
                    median = (minHeap.top()+maxHeap.top())/2.0;
                }            
        }
        else{
            // maxHeap.size() < minHeap.size()
            
            if(num > median){
                //right m jao
                int top = minHeap.top();
                minHeap.pop();
                maxHeap.push(top);
                minHeap.push(num);
                median = (minHeap.top()+maxHeap.top())/2.0;
            }
            else{
                //left m processing
                maxHeap.push(num);
                median = (minHeap.top()+maxHeap.top())/2.0;
            }            
        }
    }
    
    double findMedian() {
       return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */