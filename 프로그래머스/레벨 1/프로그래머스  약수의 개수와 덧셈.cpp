

#include <string>
#include <vector>

using namespace std;

bool find(int num){
    int div = 0;
    for(int i=1;i<=num;i++){
        if(num % i == 0){
            div++;
        }
    }
    
    if(div % 2 == 0)
        return true;
    else
        return false;
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int i=left;i<=right;i++){
        if(find(i))
            answer += i;
        else
            answer -= i;
    }
    
    return answer;
}













