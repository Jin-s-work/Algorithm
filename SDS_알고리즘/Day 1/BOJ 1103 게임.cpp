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

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

char c[51][51];
int arr[51][51];
bool check[51][51];
int dp[51][51];

int DFS(int x, int y){
    
    if(x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == 0)
        return 0;
    // 범위를 넘으면 0을 리턴
    
    if(check[x][y]){
        cout << -1 << '\n';
        exit(0);
    }
    // check가 이미 지낫을 경우 -1을 출력하고 끝냄
    
    if(dp[x][y] != -1)
        return dp[x][y];
    // dp가 바뀌지 않았을 경우 그냥 dp를 리턴함
    
    check[x][y] = true;
    dp[x][y] = 0;
    
    // 위에가 모두 아닐 경우 check를 true로 해주어 지나간 표시를 해주고 dp도 0으로 만들어준다.
    
    for(int i=0;i<4;i++){
        int nx = x + (arr[x][y] * dx[i]);
        int ny = y + (arr[x][y] * dy[i]);
        
        dp[x][y] = max(dp[x][y], DFS(nx, ny) + 1);
        // 원래의 dp와 다음의 DFS에 1을 더해서 오는 것과 비교해서 더 큰것으로
        // dp에는 즉 갈수 있는 만큼을 출력한다.
        
        // DFS로 nx,ny 즉 다음으로 이동하는 것을 가정하여 해보았을 경우의 수 + 1이
        // 원래의 dp보다 작거나 같을 경우에는 그냥 dp를 넣어 그 x,y에서 갈 수 있는 수를 나타내는 것
        // (최대)
    }
    
    check[x][y] = false;
    // 바꾸어 주고 false로 만듬
    
    return dp[x][y];
    
    
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> c[i][j];
            if(c[i][j] == 'H')
                arr[i][j] = 0;
            else
                arr[i][j] = c[i][j] - '0';
            // char로 받아서 int형의 수로 바꾸어주기
        }
    }
    
    memset(dp, -1, sizeof(dp));
    // 처음에 모두 dp를 -1로 해준다.
    
    
    int ans = DFS(0,0);
    
    cout << ans;

    return 0;

}
