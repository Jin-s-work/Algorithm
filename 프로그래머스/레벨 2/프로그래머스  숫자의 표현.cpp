

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    for(int i=1;i<=n/2;i++){
        int sum = 0;
        for(int j=i;j<=n;j++){
            if(sum > n){
                sum = 0;
                break;
                // 넘을 경우 sum을 0으로 해주고 break
            }
            else if(sum == n){
                answer++;
                break;
            }
            
            sum += j;
        }
    }
    
    // 전 방법이랑은 먼가 다른데,, 역시 시간초과
    // 뒤에서부터 해서 그런가 앞에서 부터로 다시 해봐야겠다...
    
    // 전에는 for와 while을 사용했는데 시간 초과가 났고, 이번에는 for만 썼는데 시간초과가 안났다..
    // while을 쓸 경우 제대로 탈출을 안해서 그런가.. 흠
    
    return answer;
}













