#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    long long N, K;
    std::cin >> N >> K;
    
    std::vector<pair<int, int>> numbers;
     for(int i = 0; i < N; i++) {
        pair<int, int> p;
        cin >> p.first;
        p.second = i;
        numbers.push_back(p);
    }
    std::sort(numbers.begin(), numbers.end());
    
    int beg = 0;
    int end = numbers.size() - 1;
    
    while(beg != end) {
        int currSum = numbers[beg].first + numbers[end].first;
        
        if(currSum == K) {
            cout << numbers[beg].second << " " << numbers[end].second;
            break;
        }
        
        if(currSum > K) 
            end--;
        else
            beg++;
    }
    
    return 0;
}
