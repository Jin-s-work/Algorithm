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


ll dp[101][10001];
ll arr[10001];
ll memo[101];
ll cost[101];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        cin >> memo[i];
    }   // 활성화 되있는 앱의 메모리
    int sum = 0;
    for(int i=1;i<=n;i++){
        cin >> cost[i];
        sum += cost[i];
    }   // 앱을 비활성화 했을 경우의 비용
    
    int ans = MAX;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){        // cost들을 총 더한 합 보다 작은 범위에서 찾기
            if(j - cost[i] >= 0)        // cost가 j보다 작을 경우에
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - cost[i]] + memo[i]);
            else{                       // j에는 cost[i]만큼 차이나는 값과 비교하여 memo[i]를 더하기
                dp[i][j] = dp[i-1][j];
            }
            
            // dp는 메모리들을 뜻하는데 m을 넘을 경우 메모리가 확보된다. 이때의 j가 곧 ans
            if(dp[i][j] >= m)
                ans = min(ans, j);
            // dp가 m을 넘었을 경우에 즉 넘을 경우 필요한 메모리가 확보되므로 넘은 경우에만 j를 ans와 비교한다.
        }
    }
    
    cout << ans;
    
    
    return 0;
    
}

// 예전에 풀때는 역시 디피가 익숙하지 않아 굉장히 길게 생각하고 풀이하였다
// 디피를 많이 풀고 하다보니 바로 이해가 감
