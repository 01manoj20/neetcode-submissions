class MedianFinder {
public:
    priority_queue<int> p1;
    priority_queue<int> p2;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        p1.push(num);
        if(!p2.empty() && (p2.top()>(-p1.top())))
        {
            p2.push(-p1.top());
            p1.pop();
        }
        if(p1.size()>p2.size()+1)
        {
            p2.push(-p1.top());
            p1.pop();
        }
        if(p2.size()>p1.size()+1)
        {
            p1.push(-p2.top());
            p2.pop();
        }

    }
    
    double findMedian() {
        if(p1.size() == p2.size())
            return (p1.top()-p2.top())/2.0;
        if(p1.size() > p2.size())
            return p1.top();
        if(p1.size() < p2.size())
            return -p2.top();
        
    }
};
