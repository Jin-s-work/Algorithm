


#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    long long d = sqrt(n);
    
    if(d*d == n){
        answer += (d+1)*(d+1);
    }
    // 에스토스테네스의 체 같은 거 안쓰고 그냥 long long으로 d를 받아서 확인하고 맞으면
    // 넣고 아니면 -1을 그냥 넣으면 된다.. 너무 꼬아서 생각함
    else
        answer += -1;
    
    
    return answer;
}












