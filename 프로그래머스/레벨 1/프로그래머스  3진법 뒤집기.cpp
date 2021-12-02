
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int>v;
    
    int tmp = n;
    while(n){
        v.push_back(n % 3);
        n /= 3;
    }
    
    reverse(v.begin(), v.end());
    
    int num = 0;
    for(int i=0;i<v.size();i++){
        num = v[i] * pow(3, i);
        answer += num;
        
    }
    
    // 그냥 가장 나이브하게 품
    
    return answer;
}














