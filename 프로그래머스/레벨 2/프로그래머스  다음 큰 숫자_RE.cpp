#include <string>
#include <vector>

using namespace std;

int find(int a){
    int cnt = 0;
    while(a){
        if(a % 2 == 1)
            cnt++;
        
        a /= 2;
    }
    // 2 10 0
    // 2  5 1
    // 2  2 0
    //    1
    
    return cnt;
    
}

int solution(int n) {
    int answer = 0;
    
    int num = n;
    while(1){
        
        num++;
        if(find(num) == find(n)){
            answer = num;
            break;
        }
    }
    
    
    return answer;
}

// 본의 아니게 전에 코드와 거의 똑같이 짰다.. 싱기

// #include <string>
// #include <vector>

// using namespace std;

// int two(int num){
//     int cnt = 0;
//     while(num){
//         if(num % 2 == 1)
//             cnt++;
//         num /= 2;
//     }
    
//     return cnt;
    
// }


// int solution(int n) {
//     int answer = 0;
    
//     int num = two(n);
//     int tmp = n;
//     while(1){
        
//         tmp++;
//         if(two(tmp) == num){
//             answer = tmp;
//             break;
//         }
    
//     }
    
//     return answer;
// }
