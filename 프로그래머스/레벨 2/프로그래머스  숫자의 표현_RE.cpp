#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    // 자연수 n 자체의 경우를 위해 1로
    
    // 연속한 자연수로 표현하기
    // i를 1부터 n-1까리로 하여서 n전까지의 모든 자연수에 따라 조사한다.
    // j의 경우에서는 i부터 n까지의 합을 구하는 과정으로
    // sum이 n보다 클 경우에는 바로 j에서 나오고, (계속 어차피 더 커질 것 이므로)
    // sum이 n일 경우에도 answer를 증가시키고 나온다. (이것도 어차피 더 커질 것 이므로)
    // 둘다 아니고 sum < n 인 경우에는 sum에 j를 더해주면서 중첩시켜준다.
    // 복잡한 알고리즘일 줄 알았는데 완전탐색을 사용하고 생각보다 괜찮았다.
    for(int i=1;i<n;i++){
        int sum = 0;
        for(int j=i;j<=n;j++){
            if(sum > n){
                break;
            }
            else if(sum == n){
                answer++;
                break;
            }
            sum += j;
        }
        
    }
    
    
    return answer;
}


// #include <string>
// #include <vector>

// using namespace std;

// int solution(int n) {
//     int answer = 1;
    
//     for(int i=1;i<=n/2;i++){
//         int sum = 0;
//         for(int j=i;j<=n;j++){
//             if(sum > n){
//                 sum = 0;
//                 break;
//                 // 넘을 경우 sum을 0으로 해주고 break
//             }
//             else if(sum == n){
//                 answer++;
//                 break;
//             }
            
//             sum += j;
//         }
//     }
    
//     // 전 방법이랑은 먼가 다른데,, 역시 시간초과
//     // 뒤에서부터 해서 그런가 앞에서 부터로 다시 해봐야겠다...
    
//     // 전에는 for와 while을 사용했는데 시간 초과가 났고, 이번에는 for만 썼는데 시간초과가 안났다..
//     // while을 쓸 경우 제대로 탈출을 안해서 그런가.. 흠
    
//     return answer;
// }
