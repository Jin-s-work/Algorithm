#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    
    long long tmp = num;
    // 여기에서 num을 long long으로 받는 것이 중요한데,
    // 왜냐하면 계속 홀수가 나올 경우 3을 곱하게 되는데, 범위를 넘어버리면 처리 할 수가 없다.
    int answer = 0;
    
    while(tmp != 1){
        if(tmp % 2 == 0){
            tmp /= 2;
            answer++;
        }
        else if(tmp % 2 == 1){
            tmp = tmp * 3 + 1;
            answer++;
        }
        
        if(answer > 500){
            answer = -1;
            break;
        }
    
        }
    
    return answer;
}
