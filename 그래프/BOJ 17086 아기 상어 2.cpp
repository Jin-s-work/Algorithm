
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


struct baby{
    int x;
    int y;
};

queue<baby>q;
int arr[51][51];
int dx[8] = {0,0,1,-1,-1,1,1,-1};
int dy[8] = {1,-1,0,0,-1,1,-1,1};       // 대각선도 포함된다.
int ans = 0;

void BFS(){     // 밑의 main함수에서 queue에 상어가 있는 곳은 다 넣어줬으므로 그걸 기반으로 해본다.
    
    while(!q.empty()){      // struct로 queue안에 구조체를 만들어 x,y를 저장해준다.
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        
        for(int i=0;i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(!arr[nx][ny]){       // arr가 1이면 상어가 있으므로
                q.push({nx, ny});       // 그 좌표를 queue에 넣어줌
                arr[nx][ny] = arr[x][y] + 1;
                // 그러고, nx,ny의 좌표를 x,y에서 1이동 하므로 1 더해준다.
            }
        }
    }
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            // arr을 입력 받고,
            if(arr[i][j])       // arr이 상어가 있을 경우 queue에 먼저 넣어줌
                q.push({i, j});
        }
    }
    
    BFS();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ans < arr[i][j])     // arr이 더 크면
                ans = arr[i][j];    // ans에 넣어준다.
        }
    }
    
    cout << ans-1;
    // 상어가 1이므로, 값은 1 적어야 한다.
    
    return 0;
}
