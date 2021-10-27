
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

ll dp[1500101];
int times[1500101];
int price[1500101];



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        cin >> times[i] >> price[i];
    }

    
    for(int i=1;i<=n;i++){
        
        dp[i + times[i]] = max(dp[i + times[i]], dp[i] + price[i]);
        // 일을 수행하는 경우
        // (현재 일을 끝냈을 때 돈) + (일을 마친 다음 날의 최대 돈),
        // (일을 수행하지 않았을때의 돈) 으로 나누어서 최대를 찾는다.
        
        // xcode에서는 먼가 안되는데 그냥 해볼것.. 은 안된다.
        // 알고보니 위에서 고치다가 i--라고 한거 같은데 고치니까 되려나 되네..
        // 한번 더 outofbound가 떠서 위에 배열에서 더 넣어주니까 왠지 될거 같다.
        
        dp[i+1] = max(dp[i], dp[i+1]);
        // 일을 수행하지 않고, 그냥 건너뛰는 것을 의미함
        
    }
    
    cout << dp[n+1] << '\n';
    

    
    return 0;
}


// n이 엄청 크므로 완전 탐색으로 하면 안되고 dp로 해야 한다.

// dp[i]가 i일째에 가능한 최대 금액이라고 하면
// i일을 포함하는 경우 그 다음 일을 정할 수 있는 날은 i + times[i]일이다.
// 따라서 dp[i + times[i]] = max(본인, dp[i] + price[i])가 된다.

// i일을 포함하지 않을 경우 그 다음 일을 정할 수 있는 날은 i+1일이므로,
// dp[i+1] = max(dp[i+1], 본인) 이 된다.
