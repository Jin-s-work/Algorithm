
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    int tmp = x;
    int num = 0;
    while(x){
        num += x % 10;
        x /= 10;
    }
    
    if(tmp % num == 0)
        answer = true;
    else
        answer = false;
    
    return answer;
}
