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
#include <sstream>

// control i
#define MAX 987654321
#define mod 1000000000
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


ll dp[201][201];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> k;
    
    for(int i=0;i<=n;i++){
        dp[1][i] = 1;
    }   // 1개 더해서 i가 나오려면 1만 가능하다.
    
    for(int i=2;i<=k;i++){
        for(int j=0;j<=n;j++){
            for(int l=0;l<=j;l++){
                dp[i][j] += dp[i-1][l];
            }
            dp[i][j] %= mod;
        }
    }
    // dp로 i개를 사용하여 j를 만들기 위해서는 i-1개들을 사용한 합들에 대해서
    // 0부터 j까지를 모두 더해주어야 한다.
    // dp[i][j] = dp[i-1][0] + dp[i-1][1] + ... dp[i-1][j]
    // (1개로 0) + (1개로 2), (1개로 1) + (1개로 1), (1개로 2) + (1개로 0)
    
    cout << dp[k][n];
    
    
    return 0;
    
}
