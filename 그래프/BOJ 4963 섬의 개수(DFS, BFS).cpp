
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
int h, w;

bool check[51][51];
int arr[51][51];
int dx[8] = {0,0,1,-1, 1, 1, -1, -1};
int dy[8] = {1,-1,0,0, 1, -1, 1, -1};
int ans = 0;

void BFS(int x, int y){
    queue<pair<int, int>>q;
    q.push({x, y});
    check[x][y] = true;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        
        for(int i=0;i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx > h || ny < 0 || ny > w)
                continue;
        
            if(!check[nx][ny] && arr[nx][ny]){
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        
        }
        
        
    }
    
    
}

void DFS(int x, int y){
    
    check[x][y] = true;
    
    for(int i=0;i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx > h || ny < 0 || ny > w)
            continue;
        
        if(!check[nx][ny] && arr[nx][ny]){
            check[nx][ny] = true;
            DFS(nx, ny);
        }
        
        // DFS에서는 처음 간 곳을 true로 하고, 방향에 따라 나가면 continue
        // check가 false이고, arr가 true이면은 check를 true로 바꾸고, 다음 좌표에 따라 DFS해준다.
        
    }
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(1){
        
        cin >> w >> h;
        
        if(w == 0 && h == 0)
            break;
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> arr[i][j];
            }
        }
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(!check[i][j] && arr[i][j]){
                    ans++;
                    BFS(i, j);
                }
            }
        }
        
        cout << ans << '\n';

        memset(check, false, sizeof(check));
        memset(arr, false, sizeof(arr));
        // 계속 반복하여 주므로, memset으로 초기화 해준다.
        ans = 0;
        
    }
    
    
    return 0;
}


// 처음에는 익숙하지 않았지만, 그래도 계속 하다 보니까 DFS가 좀 익숙해진 듯..
// 더 많이 풀어봐야겟다

// BFS, DFS 모두 구현해 보았다.
