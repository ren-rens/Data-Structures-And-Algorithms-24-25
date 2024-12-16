#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

std::priority_queue<double> maxHeap;
std::priority_queue<double, std::vector<double>, std::greater<double>> minHeap;
    

double findMedian(){
    if(maxHeap.size() == minHeap.size()){
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
    
    return maxHeap.size() > minHeap.size()? maxHeap.top() : minHeap.top();
}

void print(){
    double result = findMedian();
        
    std::cout << result << std::endl;
}

void input(){

    double element = 0;
    std::cin >> element;
        
    if(maxHeap.empty() || element < maxHeap.top()){
        maxHeap.push(element);
    }
    else{
        minHeap.push(element);
    }
    
    while(maxHeap.size() + 1 < minHeap.size()){
        double current = minHeap.top();
        minHeap.pop();
        maxHeap.push(current);
    }
    
    while(maxHeap.size() > 1 + minHeap.size()){
        double current = maxHeap.top();
        maxHeap.pop();
        minHeap.push(current);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int N = 0;
    std::cin >> N;
    
    
    for(int i = 0; i < N; i++){
        input();
        
        print(counter);
    }
    
    return 0;
}
