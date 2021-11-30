

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i=1;i<=n;i++){
        if(n % i == 0)
            answer += i;
    }
    // 범위가 작아서 이렇게 해도 되는듯..?
    
    return answer;
}













