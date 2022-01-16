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

int gcd(int a, int b){

    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

#define MAXIMUM 100
#define MAXI 1000000000
int dp[201][101];


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m >> k;
    
    n += m;
    // n은 n+m으로
    
    dp[0][0] = 1;
    // 0개에서 0개를 고르는 경우는 1
    
    for(int i=1;i<=n;i++){
        dp[i][0] = 1;
        // i개에서 0을 고르는 경우는 1
        
        for(int j=1;j<=i && j<=m;j++){  // j가 i를 넘을 수 없고 m도 넘으면 안된다.
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            // 파스칼의 법칙
            
            if(dp[i][j] > MAXI)
                dp[i][j] = MAXI + 1;
            // 만약에 범위가 넘어가면 최대보다 1 크게 설정한다.
        }
        
    }
    // 이 부분은 그냥 조합인 DP 구하는 과정
    
    
    if(dp[n][m] < k){
        cout << "-1";
        return 0;
    }
    // dp[n][m]이 만약 k보다 작은 값일 경우 -1을 출력한다.
    // 왜냐하면 사전에 수록되어있는 문자열의 개수가 k보다 작으면 -1을 출력해야 하므로
    
    while(n){       // n이 아직 0이 아닐 경우 ( 0 이면 아예 안되기도 함 그 전에 끝 )
        if(dp[n-1][m] >= k)     // k보다 크면 즉 그 전에가 안바뀌고 a였다는 것을 의미
            cout << "a";        // [n-1][m] 이 k 이상일 경우 a를 출력하고
        else{
            cout << "z";        // 아닐 경우 z를 출력한다.
            
            k -= dp[n-1][m--];
            // k에서 dp[n-1][m]을 빼고 m을 1 줄여준다.
            
            // 왜냐하면 z로 결정이 나면 그 앞의 'a' 일 때의 경우의 수를 빼주어야 그 다음부터 z이므로
            // dp[n-1][m]을 빼주고, m도 작게 하는 것이다.
        }
        
        n--;
        // n을 줄여준다.
    }
    
    
    

    return 0;

}

// n개의 a와 m개의 z









//
//
//
//
//cin >> n >> k;
//
//priority_queue<int>pq;
//vector<int>v;
//
//for(int i=0;i<n;i++){
//    int a;
//    cin >> a;
//    v.push_back(a);
//}

//
//
