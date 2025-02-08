class MedianFinder {
private:
    std::priority_queue<int> maxQ;
    std::priority_queue<int, vector<int>, std::greater<>> minQ;
public:
    MedianFinder() {}
    
    void addNum(int num) 
    {
        if(maxQ.empty() || num < maxQ.top())
            maxQ.push(num);      
        else
            minQ.push(num);

        while(maxQ.size() > minQ.size() + 1)
        {
            int el = maxQ.top();
            maxQ.pop();
            minQ.push(el);
        }
        
        while(minQ.size() > maxQ.size() + 1)
        {
            int el = minQ.top();
            minQ.pop();
            maxQ.push(el);
        }
    }
    
    double findMedian() 
    {
        if(maxQ.size() == minQ.size())
            return (maxQ.top() + minQ.top()) / 2.0;

       return (maxQ.size() > minQ.size() ? maxQ.top() : minQ.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
