

#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    while(n){
        answer.push_back(n % 10);
        n /= 10;
    }
    // 되게 간단
    
    
    return answer;
}













