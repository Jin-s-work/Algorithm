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

int dp[301];
int arr[301];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    dp[0] = arr[0];             // 10
    dp[1] = max(arr[0] + arr[1], arr[1]);       // 점프해서 2번째부터 시작할 수도 있으므로
    dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);  // 0에서 2로 못가는데 왜 바로 한거디
    // 2까지 비교를 해주어야 하고 1,2에서도 각각 합을 최대와 비교해주어야 한다.
    
    if(n > 2){
        for(int i=3;i<n;i++){
            dp[i] = arr[i] + max(dp[i-3] + arr[i-1], dp[i-2]);
            // dp[i-3]에서 arr[i-1]을 더해준 것이나, dp[i-2]를 해줌으로서
            // 그 전전에서 왔는지 그 전에서 왔는지를 표시해준다.
            // dp[i-2]를 그냥 해줄 경우 여기까지의 경우의 수를 포함하므로 그냥 이렇게 해주면 된다.
            // 여기서 크기를 비교해서 그냥 arr[i]와 더하면 되는 것이다.
        }
    }
    
    
    cout << dp[n-1];
    
    
    
    return 0;
    
}
