

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int price, int money, int count) {
    long long answer = 0;
    
    long long num = 0;
    long long tmp = price;
    for(int i=0;i<count;i++){
        num += price;
        price += tmp;
    }
    
    answer = num - money;
    
    if(answer < 0)
        return 0;
    
    return answer;
    
    
}













