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


ll dp[1025];
int price[1025];
int arr[1025];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> m >> n;
    
    vector<pair<int, int>> v(n);
    
    for(int i=0;i<n;i++){
        // 홍보할 때 비용 / 고객의 수
        cin >> v[i].first >> v[i].second;
        
    }
    
    
    dp[0] = 0;
    
    for(int i=1;i<=m;i++){
        dp[i] = MAX;
        for(auto k : v){
            int tmp = max(i - k.second, 0);
            // 즉, i - 고객의 수가 음수일 경우에는 0부터 해주고 아닐 경우에는 그 수 부터해준다.
            for(int l=tmp;l<=i-1;l++){
                dp[i] = min(dp[i], dp[l] + k.first);
            }
            // i에 대해서 dp[i]와 tmp부터 i-1까지를 해서 dp[l] + 홍보할 때 비용
            // 을 비교해서 더 작은 값을 비교한다.
            
        }
    }
    
    
    cout << dp[m];
    
    
    // 동전 문제와 같이 dp[j - price[i]] 와 같은 방법으로 하려고 했는데
    // 되긴 될거같지만 이 문제에서는 중복을 주로 활용하여 하는 것이 포인트 인 것 같아
    // dp[i + k * p]와 같은 구조가 좋을 것 같다.
    
    
    return 0;
    
}

