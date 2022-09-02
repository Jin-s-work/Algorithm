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
#define mod 1000000000
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;

int arr[501][501];
int dp[501][501];
bool check[501][501];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int DFS(int x, int y){
    
    if(x == n && y == m)
        return 1;
    // 제일 마지막일 경우 1을 리턴
    
    if(check[x][y])
        return dp[x][y];
    // check가 이미 방문 되었을 경우 dp를 리턴한다.
    
    check[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx > 0 && nx <= n && ny > 0 && ny <= m){
            if(arr[x][y] > arr[nx][ny])   // 범위에 있고, 내림차순이면, dp[x][y]에 DFS 값을 더해줌
                dp[x][y] += DFS(nx, ny);
        }
        // 여기의 부분이 사실 되게 어려운데
        // 탐색을 해나가면서 끝으로 가면 1을 리턴해준다.
        // 또한, 이렇게 하다가 끝에 도달하였을 경우 다시 돌아오면서 DFS로 구한 값들을 dp에 더해주는 것이다.
        // https://wootool.tistory.com/83 링크 첨부
        
        // DFS로 들어가서 dp[x][y]를 더해주고 만약 또 다른 dp가 있으면 더 더해지는 경우 이므로
        // 방향들에 대해 조사를 해줄 수가 있는 것이다.
    }
    
    return dp[x][y];
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
        }
    }
    
    cout << DFS(1, 1);
    
    
    return 0;
    
}

// 처음에는 밑에와 같은 식으로 점차 쌓아가면서 했으나
// 여기서 원하는 값이 최단 경로가 아니므로 여기 저기 방향으로 접근이 가능했으므로 DP라기 보다는 DFS로 하는게 맞는거
// 같기도...


//
//cin >> n >> m;
//
//for(int i=0;i<n;i++){
//    for(int j=0;j<m;j++){
//        cin >> arr[i][j];
//    }
//}
//
//memset(dp, 0, sizeof(dp));
//dp[0][0] = 1;
//for(int i=0;i<m-1;i++){
//    if(arr[0][i] > arr[0][i+1])
//        dp[0][i+1] = 1;
//}
//
//for(int i=0;i<n-1;i++){
//    if(arr[i][0] > arr[i+1][0])
//        dp[i+1][0] = 1;
//}
//
//for(int i=1;i<n;i++){
//    for(int j=1;j<m;j++){
//        bool check = false;
//        if(arr[i-1][j] > arr[i][j]){
//            dp[i][j] += dp[i-1][j];
//            check = true;
//        }
//        if(arr[i][j-1] > arr[i][j]){
//            dp[i][j] += dp[i][j-1];
//            check = true;
//        }
//        if(arr[i][j+1] > arr[i][j]){
//            dp[i][j] += dp[i][j+1];
//        }
//        if(arr[i+1][j] > arr[i][j]){
//            dp[i][j] += dp[i+1][j];
//        }
//        if(!check)
//            dp[i][j] = 0;
//    }
//}
//
//for(int i=0;i<n;i++){
//    for(int j=0;j<m;j++){
//        cout << dp[i][j] << " ";
//    }
//    cout << '\n';
//}
//
//cout << dp[n-1][m-1];
//
//
//
