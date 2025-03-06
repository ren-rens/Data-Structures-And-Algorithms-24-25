#include <bits/stdc++.h>
using namespace std;

std::map<std::string, size_t> mp;

int main() 
{
   std::string word;
    while (cin >> word) 
        mp[word]++;
    
    for (const auto& el: mp) 
    {
        if (el.second == 1)
            cout << el.first << '\n';
    }
    
    return 0;
}
