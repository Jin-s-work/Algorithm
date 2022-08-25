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


int dp[101][100001];
int arr[10001];
int w[101];
int v[101];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    
    cin >> n >> k;
    // 최대 무게 k
    
    for(int i=1;i<=n;i++){
        // 무게, 가치
        cin >> w[i] >> v[i];
    }
    
    // dp[i][j]는 i는 물건 개수, j는 무게를 뜻한다. 즉 물건 개수, 무게에 맞는 최대 값을 찾는다.
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j - w[i] >= 0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            // 물건 개수가 하나 늘면서 그냥 아무것도 안하거나, 무게는 j - w[i]이고, v[i]가 증가시킬 때의
            // 값과 dp[i-1][j] 그냥 하는 것을 비교한다.
            else
                dp[i][j] = dp[i-1][j];
            // 만약 j-w[i]가 음수이면 비교안하고 그냥 한다.
        }
        
    }
    
    cout << dp[n][k];
    
    
    
    
    
    return 0;
    
}

