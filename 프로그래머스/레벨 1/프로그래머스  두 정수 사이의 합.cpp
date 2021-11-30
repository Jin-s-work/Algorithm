
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;
    
    if(a >= b){
        int tmp = b;
        b = a;
        a = tmp;
    }
    // 크기 비교를 해주어야 함
    
    for(int i=a;i<=b;i++){
        answer += i;
    }
    
    return answer;
}














