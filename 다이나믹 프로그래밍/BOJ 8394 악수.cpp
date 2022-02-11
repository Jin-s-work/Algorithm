

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


ll dp[10000001];


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i=3;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10;
    }
    
    cout << dp[n];
    
    return 0;

}


