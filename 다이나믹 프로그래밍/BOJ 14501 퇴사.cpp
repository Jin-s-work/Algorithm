
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
#include <set>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h, w;


int times[16];
int price[16];
int ans = 0;
int dp[16];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        cin >> times[i] >> price[i];
    }
    
    int next = 0;
    for(int i=n;i>0;i--){
        next = times[i] + i;
        // 다음은 time을 더했을 경우
        
        // i는 위에서 줄어들게 한다. 넘어가는지를 확인하기 위해서
        // 즉 next는 시간을 더 하였을 때 범위를 넘어가는지를 확인하기 위함이다.
        
        if(next > n+1)
            dp[i] = dp[i+1];
        // next가 n+1을 넘는 경우, 즉 시간을 넘을 경우 i를 다시 원래대로 해줌
        // 즉 지나감.. ( 왜냐하면 줄어드는 수 이므로..!)
        else{
            dp[i] = max(dp[i+1], dp[next] + price[i]);
        }   // dp는 다음의 dp나 next에 그 price를 더하는 경우의 최대를 dp에 넣어준다.
        
        
    }
    
    
    cout << dp[1];
    // 뒤에서 앞으로 오므로 제일 앞을 출력한다.
    
    
    return 0;

}

