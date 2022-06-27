#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    long long answer = 0;
    
    long long dp[5001] = {0,};
    // dp의 처음시작을 0으로 설정해주는것을 안하면 틀림.. 왜지
    
    dp[0] = 1;
    dp[2] = 3;
    
    if(n % 2 == 1)
        return 0;
    
    for(int i=4;i<=n;i+=2){
        dp[i] += 3 * dp[i-2];
        for(int j=i-4;j>=0;j-=2)
            dp[i] += dp[j] * 2;
        // dp[i]의 두번째 전에는 3개를 곱해주고
        // 그 i에 관해서는 계속 2배를 하면서 더해주어 dp[i]에 더해준다.
        // 사실 설명하기가 되게 어렵기도 하고 100퍼센트 이해하지는 못함..
        
        dp[i] %= 1000000007;
    }
    
    answer = dp[n];
    
    return answer;
}















