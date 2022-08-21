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

int dp[100001];
int arr[101];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> k;
    
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    
    
    for(int i=1;i<=k;i++){
        dp[i] = MAX;
    }
    // 처음에는 모든 수에 대해서 최소를 구하기 위해 MAX로 놓는다.
    
    for(int i=1;i<=n;i++){
        dp[arr[i]] = 1;
        // 값에 관한 dp는 다 1로 한다.
        // arr[i]의 값이 0은 아니므로 1로 놓는다.
    }
    
    dp[0] = 0;
    // 0일 경우는 0
    
    for(int i=1;i<=n;i++){              // arr[i]에 대해 모든 값을 찾기 위하여 1-n으로 한다.
        for(int j=arr[i];j<=k;j++){     // j는 arr[i]부터 제일 최대인 k까지 찾아본다.
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);
            // 원래의 dp[j]와 거기서 arr[i]를 빼고 경우의 수를 늘려서 더 작은 것과 비교
            // 최소를 찾고 있으므로
            
            // j에 대해서 for문을 arr[i]부터 k까지로 해주면서 모든 경우에 대한 가지수를 고려해 볼 수 있게 하고
            // k값에 대한 dp를 찾아준다.
        }
    }
    
    if(dp[k] == MAX)
        cout << -1;
    else
        cout << dp[k];
    
    
    
    
    
    return 0;
    
}
