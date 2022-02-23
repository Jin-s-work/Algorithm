#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <functional>
#include <map>
#include <unordered_map>
#include <set>

// control i
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


ll dp[1000001];

void fib(){
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 1000000000;
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    if(n == -1){
        cout << 1 << '\n';
        cout << 1 << '\n';
        return 0;
    }
    else if(n < -1){        // 음수일 경우 양수로 바꾸어 준다.
        n *= -1;
        fib();
        // 그러고 피보나치 배열 넣기
        
        if(n % 2 == 0){     // 짝수일 경우
            cout << -1 << '\n' << dp[n];
        }
        else{               // 홀수일 경우
            cout << 1 << '\n' << dp[n];
        }
        
        return 0;
    }
    else{           // 양수일 경우에는 그냥 한다.
        fib();
        if(dp[n] > 0){          // 그러고 dp[n] 이 양수 일 경우 1, dp[n]
            cout << 1 << '\n' << dp[n];
        }
        else if(dp[n] == 0)
            cout << 0 << '\n' << 0 << '\n';
    }
    
    
    
    
    return 0;

}
