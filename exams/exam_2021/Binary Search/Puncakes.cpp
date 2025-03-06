#include <iostream>
#include <vector>
#include <algorithm>

bool canCookInTime(const std::vector<long long>& times, long long pancakes, long long time) {
    long long totalPancakes = 0;
    for (long long t : times) {
        totalPancakes += time / t;
        
        if (totalPancakes >= pancakes) {
            return true;
        } 
    }
    
    return totalPancakes >= pancakes;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    long long pancakes, cooks;
    std::cin >> pancakes >> cooks;

    std::vector<long long> times(cooks);
    for (long long i = 0; i < cooks; i++) {
        std::cin >> times[i];
    }

    long long low = 1;
    long long high = *std::min_element(times.begin(), times.end()) * pancakes; 
    
    long long result = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        if (canCookInTime(times, pancakes, mid)) {
            result = mid;
            high = mid - 1; 
        } 
        else {
            low = mid + 1; 
        }
    }

    std::cout << result;
    
    return 0;
}
