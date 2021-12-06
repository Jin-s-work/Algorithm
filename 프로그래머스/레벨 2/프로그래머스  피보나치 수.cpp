

#include <string>
#include <vector>

using namespace std;


int solution(int n) {
    int answer = 0;
    
    int fib[100001];
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 1;
    
    for(int i=0;i<n-1;i++){
        fib[i+2] = (fib[i+1] + fib[i]) % 1234567;
    }
    
    // fib[n]까지만 찾아서 되는듯
    // 그냥 이렇게만 하면 효율성 오류 날텐디.. 기억안나서 다시 찾아바야디
    
    return fib[n];
}













