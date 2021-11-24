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


int arr[101][101][101];
int ans = 0;
int dp[101][101][101];

int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0,0,0,-1,1};

queue<pair<pair<int, int>, int>>q;
int Max = 0;

void BFS(){
    
    while(!q.empty()){
        int z = q.front().first.first;
        int x = q.front().first.second;
        int y = q.front().second;
        q.pop();
        // z, x, y 순서이다.
        
        for(int i=0;i<6;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
                continue;
            // 범위넘으면 그냥 continue
            
            if(dp[nz][nx][ny] >= 0)
                continue;
            // 0 이상은 패스
            
            dp[nz][nx][ny] = dp[z][x][y] + 1;
            // dp에 1씩 더해서 넣어줌
            // 범위 안넘고, 0보다 작을 경우에만
            // 밑에서 빈공간을 -1로 해주기에 음수여야 한다.
            
            q.push({{nz, nx}, ny});
            // 범위 안넘고, 음수일 경우 다음을 q에 넣어줌
        }
        
        
    }
    
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> m >> n >> h;
    
    for(int k=0;k<h;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> arr[k][i][j];
                if(arr[k][i][j] == 1)
                    q.push({{k, i}, j});
                // 1일 경우 그 위치를 queue에 넣고 시작하게 해줌
                
                if(arr[k][i][j] == 0)
                    dp[k][i][j] = -1;
                // 0이면 dp를 -1로 만들어서 되게 한다.
            }
        }
    }
    
    BFS();
    
    for(int k=0;k<h;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[k][i][j] == -1){
                    cout << "-1" << '\n';
                    return 0;
                    // 다하고 dp에 -1이 남아있으면 -1을 출력
                }
                Max = max(Max, dp[k][i][j]);
                // 계속 이렇게 비교해서 max를 올려준다.
            }
        }
    }
    
    cout << Max << '\n';
    
    
    
    return 0;

}



