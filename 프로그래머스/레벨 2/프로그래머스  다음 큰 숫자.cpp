

#include <string>
#include <vector>

using namespace std;

int two(int num){
    int cnt = 0;
    while(num){
        if(num % 2 == 1)
            cnt++;
        num /= 2;
    }
    
    return cnt;
    
}


int solution(int n) {
    int answer = 0;
    
    int num = two(n);
    int tmp = n;
    while(1){
        
        tmp++;
        if(two(tmp) == num){
            answer = tmp;
            break;
        }
    
    }
    
    return answer;
}

// 프로그래머스를 하며 수학만 풀었더니 간단..













