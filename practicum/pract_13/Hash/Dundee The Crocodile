#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;

std::unordered_map<std::string, long long> words1, words2;
std::vector<std::string> result;

void input() {
    std::string sentence1, sentence2;

    std::getline(std::cin, sentence1);
    
    std::getline(std::cin, sentence2);

    std::stringstream ss1(sentence1);
    std::string word;
    
    while (ss1 >> word) {
        words1[word]++;
    }

    std::stringstream ss2(sentence2);
    
    while (ss2 >> word) {
        words2[word]++;
    }

}

void findUniqueWords() {
    for(const auto& word : words1) {
        if(words2.count(word.first) == 0 && word.second == 1) {
            result.push_back(word.first);
        }
    }
    
    for(const auto& word : words2) {
        if(words1.count(word.first) == 0 && word.second == 1) {
            result.push_back(word.first);
        }
    }
}

void print() {
    std::sort(result.begin(), result.end());

    for(const auto& word : result) {
        std::cout << word << std::endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    input();
    
    findUniqueWords();
    
    print();
    
    return 0;
}
