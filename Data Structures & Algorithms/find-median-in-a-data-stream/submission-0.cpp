class MedianFinder {
public:
    //Max heap
    priority_queue<int> smallHeap;
    //Min heap
    priority_queue<int,vector<int>,greater<int>> largeHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //Check if the given number is greater than the smallest element in the large heap if yes insert into large heap
        //Before that push it in to smallHeap
        smallHeap.push(num);
        //All elements in the largeHeap should be greater than smallHeap
        if(!largeHeap.empty() && smallHeap.top() > largeHeap.top()){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(smallHeap.size() > largeHeap.size() + 1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        else if(largeHeap.size() > smallHeap.size() + 1){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if(smallHeap.size() == largeHeap.size()){
            return (smallHeap.top()+largeHeap.top()) / 2.0 ;
        }
        else if(smallHeap.size() > largeHeap.size()) return smallHeap.top();
        else return largeHeap.top();
    }
};
