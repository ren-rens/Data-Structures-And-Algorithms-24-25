#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n = 0; 
    int k = 0;
    cin>>n>>k;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    
    int counter=0;
    for(auto iter = v.begin(); iter != v.end(); iter++)
    {
        if(*iter==k)
        {
            v.erase(iter);
            iter--;
        }
    }
    
    for(int i = 0; i < v.size(); i++)
        cout<<v[i] << ' ';
    
    return 0;
}
