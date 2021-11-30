
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    while(b){
        int c = a % b;
        a = b;
        b = c;
    }
    
    return a;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int num = 0;
    if(n >= m)
        num = gcd(n, m);
    else
        num = gcd(m, n);
    
    answer.push_back(num);
    answer.push_back(n * m / num);
    
    
    return answer;
}














