

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

ll dp[100001];


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> t;
    
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    dp[4] = 3;
    dp[5] = 3;
    dp[6] = 6;
    
    for(int i=7;i<=100000;i++){
        dp[i] = ((dp[i-2] + dp[i-4]) % 1000000009 + dp[i-6]) % 1000000009;
    }
    // 다이나믹 프로그래밍에서 이러한 점화식을 가진다.
    
    while(t--){
        
        cin >> n;
        
        cout << dp[n] << '\n';
    }
    
    
    
    
    
    return 0;

}


