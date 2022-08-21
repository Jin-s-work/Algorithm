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

ll dp[2][100001];        // dp의 경우 합이 커져서 2^63 - 1 까지 가므로 롱롱
ll arr[2][100001];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> t;
    
    while(t--){
        
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));

        
        cin >> n;
        
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin >> arr[i][j];
            }
        }
        
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        
        dp[0][1] = max(arr[1][0] + arr[0][1], arr[0][1]);
        dp[1][1] = max(arr[0][0] + arr[1][1], arr[1][1]);
        
        dp[0][2] = max(dp[1][0] + arr[0][2], dp[1][1] + arr[0][2]);
        dp[1][2] = max(dp[0][0] + arr[1][2], dp[0][1] + arr[1][2]);
        // 여기서 되는 경우에는 바로 대각선 밑이나 대각선 왼쪽 밑에 한번 왼쪽
        
        // 고려할 부분이 많아서 여기서 숫자를 계속 헷갈려서 썼다..
        // 그래도 혼자 풀어서 기분이 좋다
        
        ll Max = 0;

        if(n < 3){
            Max = max(dp[0][n], dp[1][n]);
        }
        // 3보다 작을 경우를 생각하여 Max 찾기
        
        
        for(int i=3;i<n;i++){
            dp[0][i] = max(dp[1][i-1] + arr[0][i], dp[1][i-2] + arr[0][i]);
            dp[1][i] = max(dp[0][i-1] + arr[1][i], dp[0][i-2] + arr[1][i]);

            if(dp[0][i] > Max){
                Max = dp[0][i];
//                ans = i;
            }
            if(dp[1][i] > Max){
                Max = dp[1][i];
//                ans = i;
            }
        }
        
        // 위의 경우에서는 3보다 작을 경우 Max를 구해줄 수 없으니
        // 위에에 대해서도 하나 해준다.
        
        cout << Max << '\n';
        
    }
    
    
    
    
    
    
    return 0;
    
}
