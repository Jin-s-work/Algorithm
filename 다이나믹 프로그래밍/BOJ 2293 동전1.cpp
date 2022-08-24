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
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


ll dp[10001];
int arr[10001];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    
    cin >> n >> k;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=arr[i];j<=k;j++){
            dp[j] += dp[j - arr[i]];
            // 경우의 수들을 더해주어야 하므로 늘때마다 그 전의 dp[j - arr[i]]를 더해준다.
        }
    }
    
    cout << dp[k];
    
    
    return 0;
    
}

