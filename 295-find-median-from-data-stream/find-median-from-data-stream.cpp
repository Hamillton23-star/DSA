class MedianFinder {
public:

priority_queue<int>max_heap;
priority_queue<int, vector<int> , greater<int>> min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // adding 
        if(max_heap.size() == 0 || num < max_heap.top()) {
            max_heap.push(num);
        } 

        else min_heap.push(num);
        

        if(max_heap.size() > min_heap.size() + 1) {
            auto top = max_heap.top();
            min_heap.push(top);
            max_heap.pop();
        }
        
        else if(max_heap.size() < min_heap.size()) {
            auto top = min_heap.top();
            max_heap.push(top);
            min_heap.pop();
         }
    }
    
    double findMedian() {
        if ((max_heap.size() + min_heap.size()) % 2 == 0) {
            return (max_heap.top() + min_heap.top()) / 2.0;
        } else {
            return max_heap.top();
        }
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */