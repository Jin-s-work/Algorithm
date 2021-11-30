

#include <string>
#include <vector>
#include <math.h>

using namespace std;


int solution(int n) {
    int answer = 0;
    
    vector<int>v(n+1, 0);
    // 처음 먼저 모든 수를 0으로 해준다.
    
    for(int i=2;i<=n;i++){
        if(!v[i])
            answer++;
        for(int j=i;j<=n;j+=i){
            v[j] = 1;
        }
        // i가 아무것도 안바뀐 0일 경우에는 answer를 늘려준다.
        // 그러고 그 i에서 n까지 i씩 더해주면서 그 배열을 1로 만들어
        // 배수임을 파악하여 1로 바꾸어 준다. 즉 소수가 아님
        // 원래 했던 sqrt(n)을 사용한 방법은 범위가 커서 루트를 해도 꽤 수가 커서 효율성에서 탈락
    }
    
    return answer;
}
