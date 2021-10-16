
#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>
#include <map>
#include <set>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;



int dp[11];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    // 111 21 12 3
    dp[4] = 7;
    dp[5] = 13;
    // 11111 1112 1121 1211 2111 113 131 311
    // 23 32 221 212 122
    
    for(int i=1;i<8;i++){
        dp[i+3] = dp[i+2] + dp[i+1] + dp[i];
    }
    
    cin >> t;
    
    while(t--){
        
        cin >> n;
        
        cout << dp[n] << '\n';
        
        
    }
    
    
    
    
    
    
    
    return 0;
}
