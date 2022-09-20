#include <string>
#include <vector>

using namespace std;

long long arr[100001];


int solution(int n) {
    int answer = 0;
    
    arr[0] = 0;
    arr[1] = 1;
    
    for(int i=2;i<=n;i++){
        arr[i] = arr[i-1] + arr[i-2];
        arr[i] %= 1234567;
    }
    
    answer = arr[n];
    
    return answer;
}




// #include <string>
// #include <vector>

// using namespace std;


// int solution(int n) {
//     int answer = 0;
    
//     int fib[100001];
//     fib[0] = 0;
//     fib[1] = 1;
//     fib[2] = 1;
    
//     for(int i=0;i<n-1;i++){
//         fib[i+2] = (fib[i+1] + fib[i]) % 1234567;
//     }
    
    
    
//     return fib[n];
// }
