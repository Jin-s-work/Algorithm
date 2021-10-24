
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


int arr[33][33];
ll dp[33][33][3];
// 마지막이 방향을 표시한다.
// [a][b][0,1,2] (a,b)에서 c로 진행할때 (a, b)까지 올 수 있는 경우의 수


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    // 0,1,2 인데 0은 가로, 1은 세로, 2는 대각선이다.
    
    dp[0][1][0] = 1;
    // 처음에는 0,1로 가로로 가므로 그 경우가 1인 것으로 시작한다.
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0)
                continue;
            if(arr[i][j] == 1)
                continue;       // 1이면 넘어가게 해야하는데, 0으로 해놔서 그냥 다 무시한듯...
            
            if(arr[i][j+1] == 0)     // 오른쪽으로 갈 수가 있다면
                dp[i][j+1][0] = dp[i][j][2] + dp[i][j][0];
            // 왜냐하면 오른쪽으로 갈때는 대각선에서 오른쪽으로 가는 경우와 오른쪽에서 오른쪽으로만 가능 하기 때문
            if(arr[i+1][j] == 0)
                dp[i+1][j][1] = dp[i][j][1] + dp[i][j][2];
            if(i+1 < n && j+1 < n){     // 먼저 대각선이 n 이상일 경우 안되고
                if(arr[i+1][j+1] == 0 && arr[i][j+1] == 0 && arr[i+1][j] == 0)
                    dp[i+1][j+1][2] = dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
            }       // 대각선은 앞의 세 블록이 다 0이어야 가능하고, 모든 방향이 가능하므로 이렇게 더해준다.
                
        }
    }
    
    cout << dp[n-1][n-1][2] + dp[n-1][n-1][1] + dp[n-1][n-1][0];
    // (n-1,n-1) 로 가는 것중에 대각선에서 오고 세로에서 오고, 가로에서 오는 것을 찾는 것 이므로 [n-1][n-1]
    // arr를 0,0부터 받으므로 n-1,n-1에서 끝나는게 맞다.
    
    return 0;
}

