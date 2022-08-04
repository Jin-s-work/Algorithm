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

// control i처
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;





int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> t;
    
    ll dp[101];
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    // 3
    // 1 2  2 1   1 1 1
    dp[4] = 7;
    dp[5] = 13;
    // 1 1 1 1 1
    // 1 1 1 2    * 4
    // 1 1 3      * 3
    // 2 2 1      * 3
    // 2 3        * 2
    
    for(int i=1;i<=13;i++){
        dp[i+3] = dp[i] + dp[i+1] + dp[i+2];
    }
    
    
    while(t--){
        
        cin >> n;
        
        cout << dp[n] << '\n';
        
    }


    
    return 0;

}

